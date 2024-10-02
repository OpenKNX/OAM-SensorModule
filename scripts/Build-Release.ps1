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

if ($releaseIndication -eq "Big") {
    # build firmware for RP2040 sensormodule breakout board
    scripts/Build-Step.ps1 release_Sensormodul_Breakout_RP2040 firmware-Sensormodul-Breakout-RP2040 uf2 Sensormodul-Breakout-Board-Just-for-testers
    # if (!$?) { exit 1 }

    # build firmware productive RP2040 sensormodule
    scripts/Build-Step.ps1 release_Sensormodul_v40_RP2040 firmware-Sensormodul-v4x-RP2040 uf2
    if (!$?) { exit 1 }

    scripts/Build-Step.ps1 release_1TE_RP2040_SmartMF firmware-SmartMF-1TE-RP2040 uf2
    if (!$?) { exit 1 }

    scripts/Build-Step.ps1 release_UP1_SENSOR_1KANAL firmware-UP1_SENSOR_1KANAL uf2
    if (!$?) { exit 1 }

    scripts/Build-Step.ps1 release_PresenceMultiSensor_ABSmartHouse firmware-ABSmartHouse-PresenceMultiSensor uf2 AB-SmartHouse-PresenceMultiSensor
    if (!$?) { exit 1 }
}

if ($releaseIndication -eq "Vpm") {
    # build firmware productive RP2040 sensormodule
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_Sensormodul_v40_RP2040_Vpm firmware-Sensormodul-v4x-RP2040 uf2
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_1TE_RP2040_SmartMF_Vpm firmware-SmartMF-1TE-RP2040 uf2
    if (!$?) { exit 1 }

    # build firmware for legacy SAMD sensormodules
    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_Sensormodul_v31_SAMD_Vpm firmware-Sensormodul-v31-SAMD bin
    # if (!$?) { exit 1 }

    # lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_Sensormodul_v30_SAMD_Vpm firmware-Sensormodul-v30-SAMD bin
    # if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_PresenceMultiSensor_ABSmartHouse firmware-ABSmartHouse-PresenceMultiSensor uf2 firmware-AB-SmartHouse-PresenceMultiSensor
    if (!$?) { exit 1 }
}

if ($releaseIndication -eq "OneWire") {
    exit 1
    # build firmware productive RP2040 sensormodule
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_Sensormodul_v40_RP2040_Wire firmware-Sensormodul-v4x-RP2040 uf2
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_1TE_RP2040_SmartMF_Wire firmware-SmartMF-1TE-RP2040 uf2
    if (!$?) { exit 1 }

    # build firmware for legacy SAMD sensormodules
    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_Sensormodul_v31_SAMD_Wire firmware-Sensormodul-v31-SAMD bin
    if (!$?) { exit 1 }

    lib/OGM-Common/scripts/setup/reusable/Build-Step.ps1 release_Sensormodul_v30_SAMD_Wire firmware-Sensormodul-v30-SAMD bin
    if (!$?) { exit 1 }
}
# execute generic post-build steps
../OGM-Common/scripts/setup/reusable/Build-Release-Postprocess.ps1 $args[0]
if (!$?) { exit 1 }

if (Test-Path -Path release-collection -PathType Container) {
    Copy-Item release/* release-collection/
}
