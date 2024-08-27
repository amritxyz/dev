rm -rf ~/hosts
touch ~/hosts
echo "127.0.0.1   localhost" >> ~/hosts
echo "::1         localhost" >> ~/hosts
echo "127.0.1.1   $(hostname).localhost $(hostname)" >> ~/hosts
