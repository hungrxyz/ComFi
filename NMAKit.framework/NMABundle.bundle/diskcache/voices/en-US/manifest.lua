_package_settings = {}
main_attribute_array = {}
package_provider = 02
voice_settings = {}

language = "English (US)"
language_id = "06"
language_loc = "English (US)"
main_attribute_array["LocalizedType"] = "announced street names"
main_attribute_array["language_code"] = "en-US"
main_attribute_array["ngLangCode"] = "eng"
marc_code = "010"
name = "English (US)"
pre_packaged = "YES"

audio_files_path = "resources"
audio_files_version = "0.5.0.201605311110"
config_file = "common.lua"
configurable = "false"
description = language_loc
feature_list = { "metric", "imperial_uk", "imperial_us" }
frequency = 16
id = package_provider..language_id
main_attribute_array["VoiceFeatures"] = "drive;walk;metric;imperialuk;imperialus;naturalguidance;trafficlights;tts"
network_provider_support_list = "all" -- not used in MOS
output_type = "tts"
pitch = 1.1
platform_support_list = { '="HERE SDK for Android":>= 1.0' }
rate = 0.22
travel_mode = "0" -- not used in MOS
tts_engine_type = { "NONE" }
voice_settings["nguidance"] = true
voice_settings["nguidance_junction"] = true
voice_settings["nguidance_stop_sign"] = true
voice_settings["nguidance_trafficlights"] = true
