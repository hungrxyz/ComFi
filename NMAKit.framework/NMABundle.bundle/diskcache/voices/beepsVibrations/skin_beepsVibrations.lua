-- ----------------------------------------------------------------------------
-- Copyright (C) 2011 Nokia Gate5 GmbH Berlin
--
-- These coded instructions, statements, and computer programs contain
-- unpublished proprietary information of Nokia Gate5 GmbH Berlin, and
-- are copy protected by law. They may not be disclosed to third parties
-- or copied or duplicated in any form, in whole or in part, without the
-- specific, prior written permission of Nokia Gate5 GmbH Berlin.
-- ----------------------------------------------------------------------------
-- 				Authors: Raul Ferrandez, Fabian TP Riek
-- ----------------------------------------------------------------------------
--             Voice Skin: beepsVibrations

description = "" 
output_type = "audio"
speaker = ""
gender = "f"                         -- without gender
travel_mode = "2"                -- only walk
language = "Beeps and Vibrations"
marc_code = ""
language_id = "1"
id = "1003"                         
config_file = "beepsVibrations/config.lua"
audio_files_path = "beepsVibrations/beepsVibrations"
audio_files_version = "0.3.0.20110622"
feature_list = { "metric", "imperial_uk", "" }
client_range = "[client >= 1.4.6.0 ]"


distances = {  }

misc =  {  

[ "beep_sound" ] = "beep"

}

check_files = { misc }
