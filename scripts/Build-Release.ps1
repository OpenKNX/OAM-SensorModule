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

$releaseIndication = $args[0]
# set product names, allows mapping of (devel) name in Project to a more consistent name in release
# $settings = scripts/OpenKNX-Build-Settings.ps1

# execute generic pre-build steps
../OGM-Common/scripts/setup/reusable/Build-Release-Preprocess.ps1 $args[0]
if (!$?) { exit 1 }

if (Test-Path -Path scripts/data -PathType Container) {
    Copy-Item scripts/data/* release/data/
    if (!$?) { exit 1 }
}

if ($releaseIndication -eq "Big") {
    # build firmware for RP2040 sensormodule breakout board
    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_Sensormodul_Breakout_RP2040 firmware-Sensormodul-Breakout-RP2040 uf2 Sensormodul-Breakout-Board-Just-for-testers
    # if (!$?) { exit 1 }

    # build firmware productive RP2040 sensormodule
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_Sensormodul_v40_RP2040 firmware-SmartMF-Sensormodul-RP2040 uf2
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_PiPico_BCU_Connector firmware-PiPico-BCU-Connector uf2
    if (!$?) { exit 1 }
    
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_1TE_RP2040_SmartMF firmware-SmartMF-1TE-RP2040 uf2
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_UP1_SENSOR_1KANAL firmware-SEN-UP1-8XTH uf2
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_UP1_PM_HF firmware-UP1-PM-HF uf2
    if (!$?) { exit 1 }

    # build firmware for OpenKNX-REG1-Base-V0
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_OpenKNX_REG1_BASE_V0 firmware-OpenKNX-REG1-Base-V0 uf2
    if (!$?) { exit 1 }

    # build firmware for OpenKNX-REG1-Base-V1
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_OpenKNX_REG1_BASE_V1 firmware-OpenKNX-REG1-Base-V1 uf2
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_RealPresence firmware-RealPresence uf2
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_RealPresence_v20 firmware-RealPresence_v2.0 uf2
    if (!$?) { exit 1 }

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

# execute generic post-build steps
../OGM-Common/scripts/setup/reusable/Build-Release-Postprocess.ps1 $args[0]
if (!$?) { exit 1 }

if (Test-Path -Path release-collection -PathType Container) {
    Copy-Item release/* release-collection/
}
