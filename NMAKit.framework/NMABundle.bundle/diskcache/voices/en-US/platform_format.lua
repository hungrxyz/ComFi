-- ----------------------------------------------------------------------------
-- Copyright (C) 2013 - 2013 HERE Global B.V., including its affiliated companies.
--
-- These coded instructions, statements, and computer programs contain
-- unpublished proprietary information of HERE Global B.V., and
-- are copy protected by law. They may not be disclosed to third parties
-- or copied or duplicated in any form, in whole or in part, without the
-- specific, prior written permission of HERE Global B.V.
-- ----------------------------------------------------------------------------
--      Author: Dirk Huppermann, Bill King
-- ----------------------------------------------------------------------------
--      Output format for Nuance Engine
--      0.4.0.XXX

function take_phoneme_if_exists( orthotext, phoneme, language, article )
    
    local result = ""
    local do_shorten, value = can_shorten( article, orthotext )
    local ortho_article = value.ortho
    local phonetic_article = value.phoneme

    if do_shorten == true then
        result = ortho_article .. orthotext
    else
        if ortho_article ~= nil and ortho_article ~= "" then
            result = ortho_article .. " " .. orthotext
        else
            result = orthotext
        end
    end
    
    if result ~= "" then
        return "!ADDRESS_MODE!" .. result .. "!NORMAL_MODE!"
    else
        return ""
    end
end


function set_result( id )

    if guidance_mode == "pedestrian" and commands_ped[ id ] ~= nil and commands_ped[ id ] ~= "" then
        result_sentence = commands_ped[ id ]
    else
        result_sentence = commands_common[ id ]
    end

    if result_sentence ~= nil and result_sentence ~= "" then

        tts_street_1 = build_streetname(tts_street_1, result_sentence, take_phoneme_if_exists)
        tts_street_2 = build_streetname(tts_street_2, result_sentence, take_phoneme_if_exists)

        tts_signpost_1 = build_signpost(tts_signpost_1, result_sentence, take_phoneme_if_exists)
        tts_signpost_2 = build_signpost(tts_signpost_2, result_sentence, take_phoneme_if_exists)

        tts_exit_number = build_signpost(tts_exit_number, result_sentence, take_phoneme_if_exists)

        natural_guidance_terms = provide_natual_guidance( {maneuver, nextManeuver}, take_phoneme_if_exists)

--        -- add comma between street name and signpost        
--        result_sentence = string.gsub(result_sentence, "!STREET! !SIGNPOST!", "!STREET!, !SIGNPOST!")
--        result_sentence = string.gsub(result_sentence, "!STREET_2! !SIGNPOST_2!", "!STREET_2!, !SIGNPOST_2!")


        result_sentence, trash = string.gsub ( result_sentence, "!PED_TURN_NO!", ped_turn_no )
        result_sentence, trash = string.gsub ( result_sentence, "!DIST!", distance_1 )
        result_sentence, trash = string.gsub ( result_sentence, "!UNIT!", usedUnit_1 )
        result_sentence, trash = string.gsub ( result_sentence, "!STREET!", escape_string(tts_street_1) )
        result_sentence, trash = string.gsub ( result_sentence, "!STREET_2!", escape_string(tts_street_2) )
        result_sentence, trash = string.gsub ( result_sentence, "!SIGNPOST!", escape_string(tts_signpost_1) )
        result_sentence, trash = string.gsub ( result_sentence, "!SIGNPOST_2!", escape_string(tts_signpost_2) )
        result_sentence, trash = string.gsub ( result_sentence, "!EXIT_NO_ROUNDABOUT!", exit_no_roundabout )
        result_sentence, trash = string.gsub ( result_sentence, "!ORIENTATION!", head_orientation )
        result_sentence, trash = string.gsub ( result_sentence, "!NG_COMMAND_1!", escape_string(natural_guidance_terms[1]) )
        result_sentence, trash = string.gsub ( result_sentence, "!NG_COMMAND_2!", escape_string(natural_guidance_terms[2]) )
        result_sentence, trash = string.gsub ( result_sentence, "!EXIT_NUMBER!", escape_string(tts_exit_number) )
        result_sentence, trash = string.gsub ( result_sentence, "!ROUTE_OPTIONS!", escape_string(route_option_string) )

--        -- replace <break> in between phonemes with 30 ms pause
--        if ( string.find( result_sentence, "<break>" ) ) then
--
--            -- first remove orthographic fallback if present
--            result_sentence, trash = string.gsub ( result_sentence, "<ESC>\\toi=nts:\"([^<]-)\"\\([^<]-)<break>(.-)", "<ESC>\\toi=nts\\%2<break>%3" )
--
--            -- then replace any breaks with pauses
--            result_sentence, trash = string.gsub ( result_sentence, "<break>", "<ESC>\\toi=orth\\ !BREAK:30! <ESC>\\toi=nts\\" )            
--        end

        -- insert comma between two consecutive phonemes( e.g. between the exit_number and exit_name )
        result_sentence, trash = string.gsub(result_sentence, "!NORMAL_MODE! !ADDRESS_MODE!", ", ")

        -- called from ruleset.lua
        result_sentence = languageSpecificMods( result_sentence )

        -- replacement of general tags with Nuance specific tags
        result_sentence, trash = string.gsub ( result_sentence, "!FREQUENCY!", frequency )

        if string.find( result_sentence, "!SET_AUDIO!" ) then
            audio_start = '<ESC>\\audio="'..audio_files_path_absolute..package.config:sub(1, 1)
            audio_end = "\"\\"
            result_sentence, trash = string.gsub ( result_sentence, "!SET_AUDIO!(.+)!SET_AUDIO!", audio_start.."%1"..audio_end )
        end

        -- replace default BREAK with 100 ms pause
        result_sentence, trash = string.gsub ( result_sentence, " !BREAK! ", " " )

        -- replace custom BREAK with a pause of specified value
        -- replace BREAK with "" for native TTS
        while string.find( result_sentence, "!BREAK:" ) do
            pauseTime, trash = string.gsub(result_sentence, ".+!BREAK:(%d+).+", "%1")
            --result_sentence, trash = string.gsub ( result_sentence, "!BREAK:"..pauseTime.."!", "<ESC>\\pause="..pauseTime.."\\", 1)
            result_sentence, trash = string.gsub ( result_sentence, "!BREAK:"..pauseTime.."!", "", 1)
        end

        result_sentence, trash = string.gsub ( result_sentence, "!NORMAL_MODE!", "" )
        result_sentence, trash = string.gsub ( result_sentence, "!ADDRESS_MODE!", "" )
        result_sentence, trash = string.gsub( result_sentence, "<ESC>", "")
        
        -- general clean-up of the prompt
        while true do
            result_sentence, b_use = string.gsub ( result_sentence, "  ", " " )
            if b_use == 0 then
                break
            end
        end

        if ( string.byte(result_sentence,-1) == 32 ) then
            result_sentence = string.sub( result_sentence, 1, -2 )
        end

        result_sentence, trash = string.gsub( result_sentence, " ,", "," )

        -- trim front and back
        result_sentence, trash = string.gsub(result_sentence, "^(%s+)(.+)(%s*)$", "%2")

    end

    return result_sentence

end

function set_result_tts( )

    if double_command then
        if sentence_1 ~= "" and sentence_1 ~= " " and sentence_1 ~= nil then
            result_sentence = sentence_1.." "..sentence_2
        else
            result_sentence = ""
        end
    else
        if sentence_1 ~= "" and sentence_1 ~= " " and sentence_1 ~= nil then
            result_sentence = sentence_1
        else
            result_sentence = ""
        end
    end

    result_sentence, b_use = string.gsub ( result_sentence, "  ", "" )

    if ( string.byte( result_sentence, -1 ) == 32 ) then
        result_sentence = string.sub( result_sentence, 1, -2 )
    end

    result_sentence = string.upper( string.sub( result_sentence, 1, 1 ) )..string.sub( result_sentence, 2 )
    
    -- remove comma from the end of the sentence (useful when natural guidance elements are added to the prompt)
    result_sentence, count = string.gsub( result_sentence, ",$", "")

    result_sentence, count = string.gsub( result_sentence, '(audio=\\"[%a%d]+.wav"\\)'..'(%.)', "%1" )
    result_sentence, count = string.gsub( result_sentence, ',%p', "." ) -- Shouldn't have to handle this, have a pre-check.
    table.insert( result_list, result_sentence)

end
