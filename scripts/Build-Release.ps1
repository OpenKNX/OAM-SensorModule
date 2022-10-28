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
# $settings = scripts/OpenKNX-Build-Settings.ps1

# execute generic pre-build steps
../OGM-Common/setup-scripts/reusable/Build-Release-Preprocess.ps1 $args[0]
if (!$?) { exit 1 }

# build firmware based on generated headerfile for PICO
../OGM-Common/setup-scripts/reusable/Build-Step.ps1 release_RP2040 firmware uf2
if (!$?) { exit 1 }

# build firmware based on generated headerfile for SAMD
../OGM-Common/setup-scripts/reusable/Build-Step.ps1 release_SAMD_v31 firmware-v31 bin
if (!$?) { exit 1 }

../OGM-Common/setup-scripts/reusable/Build-Step.ps1 release_SAMD_v30 firmware-v30 bin
if (!$?) { exit 1 }

# execute generic post-build steps
../OGM-Common/setup-scripts/reusable/Build-Release-Postprocess.ps1 $args[0]
if (!$?) { exit 1 }
