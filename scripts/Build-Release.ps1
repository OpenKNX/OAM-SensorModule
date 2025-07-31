# This script is just a template and has to be copied and modified per project
# This script should be called from .vscode/tasks.json with
#
#   scripts/Build-Release.ps1            - for Beta builds
#   scripts/Build-Release.ps1 Release    - for Release builds
#
# {
#     "label": "Build-Release",
#     "type": "shell",
#     "command": "scripts/Build-Release.ps1 Release",
#     "args": [],
#     "problemMatcher": [],
#     "group": "test"
# },
# {
#     "label": "Build-Beta",
#     "type": "shell",
#     "command": "scripts/Build-Release.ps1 ",
#     "args": [],
#     "problemMatcher": [],
#     "group": "test"
# }

# set product names, allows mapping of (devel) name in Project to a more consistent name in release
$settings = scripts/OpenKNX-Build-Settings.ps1 $args[0]
$releaseIndication = $settings["appRelease"]

# execute generic pre-build steps
lib/OGM-Common/scripts/setup/reusable/Build-Release-Preprocess.ps1 $args[0]
if (!$?) { exit 1 }

if (Test-Path -Path scripts/data -PathType Container) {
    Copy-Item scripts/data/* release/data/
    if (!$?) { exit 1 }
}

if ($releaseIndication -eq "Beta") {
    # build BETA firmware 

    # build firmware productive RP2040 sensormodule
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_SMARTMF_SENSORMODUL firmware-SmartMF-Sensormodul-RP2040 uf2
    if (!$?) { exit 1 }

    # Dominiks HF-PM
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_UP1_PM_HF firmware-UP1-PM-HF uf2
    if (!$?) { exit 1 }

    # build firmware for 1TE-RP2040-SmartMF
    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_SMARTMF_1TE_REG firmware-1TE-RP2040-SmartMF uf2
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_PresenceMultiSensor_ABSmartHouse firmware-ABSmartHouse-PresenceMultiSensor uf2 AB-SmartHouse-PresenceMultiSensor
    if (!$?) { exit 1 }

    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_PresenceMR16_ABSmartHouse firmware-ABSmartHouse-PresenceMR16 uf2 AB-SmartHouse-PresenceMR16
    if (!$?) { exit 1 }

    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_PresenceWall_ABSmartHouse firmware-ABSmartHouse-PresenceWall uf2 AB-SmartHouse-PresenceWall
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_PIPICO_BCU_CONNECTOR firmware-PiPico-BCU-Connector uf2
    if (!$?) { exit 1 }

}


if ($releaseIndication -eq "Big") {
    # build firmware for RP2040 sensormodule breakout board
    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_Sensormodul_Breakout_RP2040 firmware-Sensormodul-Breakout-RP2040 uf2 Sensormodul-Breakout-Board-Just-for-testers
    # if (!$?) { exit 1 }

    # build firmware productive RP2040 sensormodule
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_UP1_PM_HF firmware-UP1-PM-HF uf2
    if (!$?) { exit 1 }

    # RP2040
    # build firmware for OpenKNX-REG1-Base-V0
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_REG1_BASE_V0 firmware-OpenKNX-REG1-BASE-V0 uf2
    if (!$?) { exit 1 }

    # build firmware for OpenKNX-REG1-Base-V1
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_REG1_BASE firmware-OpenKNX-REG1-BASE uf2
    if (!$?) { exit 1 }

    # build firmware for PiPico-BCU-Connector
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_PIPICO_BCU_CONNECTOR firmware-PiPico-BCU-Connector uf2
    if (!$?) { exit 1 }

    # build firmware for SEN_UP1_8XTH
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_SEN_UP1_8XTH firmware-SEN-UP1-8xTH uf2
    if (!$?) { exit 1 }

    # build firmware for 1TE-RP2040-SmartMF
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_SMARTMF_1TE_REG firmware-1TE-RP2040-SmartMF uf2
    if (!$?) { exit 1 }

    # build firmware for RP2040 sensormodule 
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_SMARTMF_SENSORMODUL firmware-SmartMF-Sensormodul-RP2040 uf2
    if (!$?) { exit 1 }

    # # build firmware for SmartMF-RealPresence (old version)
    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_RealPresence firmware-RealPresence uf2
    # if (!$?) { exit 1 }

    # build firmware for SmartMF-RealPresence-V2
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_SMARTMF_REALPRESENCE_V2 firmware-SmartMF-RealPresence-V2 uf2
    if (!$?) { exit 1 }

    # # build firmware for REG1_BASE_IP
    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_DEVICE_REG1_BASE_IP firmware-REG1-BASE-IP uf2
    # if (!$?) { exit 1 }




    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_RealPresence_HLK firmware-Smart-MF-RealPresence-2.0 uf2
    # if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_PresenceMultiSensor_ABSmartHouse firmware-ABSmartHouse-PresenceMultiSensor uf2 AB-SmartHouse-PresenceMultiSensor
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_PresenceMR16_ABSmartHouse firmware-ABSmartHouse-PresenceMR16 uf2 AB-SmartHouse-PresenceMR16
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_PresenceWall_ABSmartHouse firmware-ABSmartHouse-PresenceWall uf2 AB-SmartHouse-PresenceWall
    if (!$?) { exit 1 }

    # build firmware for RP2350
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_AB_TouchRound_RP2350 firmware-AB-TouchRound-RP2350 uf2
    if (!$?) { exit 1 }
}

# Remove unnecessary OTA upload scripts
Remove-Item -Path release/OTA-Upload-Firmware-*.ps1 -ErrorAction SilentlyContinue -Force


# execute generic post-build steps
lib/OGM-Common/scripts/setup/reusable/Build-Release-Postprocess.ps1 $args[0]
if (!$?) { exit 1 }

if (Test-Path -Path release-collection -PathType Container) {
    Copy-Item release/* release-collection/
}
