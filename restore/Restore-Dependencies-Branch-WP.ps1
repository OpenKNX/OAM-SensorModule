<#
Open ■
┬────┴  Restore-Dependencies
■ KNX   2024 OpenKNX - Erkan Çolak

FILEPATH: restore/Restore-Dependencies-Branch.ps1
#>

$command = ".\Restore-Dependencies.ps1" +
" -GitCheckoutMode Branch"

# Execute the command
Invoke-Expression $command
