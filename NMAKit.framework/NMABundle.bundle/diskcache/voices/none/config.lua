
-- ----------------------------------------------------------------------------
-- Copyright (C) 2012 Nokia Gate5 GmbH Berlin
--
-- These coded instructions, statements, and computer programs contain
-- unpublished proprietary information of Nokia Gate5 GmbH Berlin, and
-- are copy protected by law. They may not be disclosed to third parties
-- or copied or duplicated in any form, in whole or in part, without the
-- specific, prior written permission of Nokia Gate5 GmbH Berlin.
-- ----------------------------------------------------------------------------
--      Authors:  Fabian TP Riek
-- ----------------------------------------------------------------------------
--             Voice Skin:  NONE

function get_text_output()
end

function get_voicefiles()

	-- Safety SpotWarner
	if trigger == "SAFETYSPOT_WARNER" then
		table.insert(result_list, misc[ "beep_sound" ] )
	end

	-- Speed Warners triggers
	if trigger == "SPEED_WARNER" then
		table.insert(result_list, misc[ "over_speed_limit_wav" ] )
	end

end
