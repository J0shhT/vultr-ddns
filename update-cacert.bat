@echo off
set "downloadUrl=https://curl.se/ca/cacert.pem"
set "destinationDir=post"
set "destination=%destinationDir%/cacert.pem"
echo Downloading public CA root certificates from %downloadUrl% to %destination%
curl --output %destination% --time-cond %destination% %downloadUrl%