#!/bin/bash
cp recorder /usr/bin/
cp service.sh /usr/bin/
cp recorder.service /etc/systemd/system/
systemctl daemon-reload 
sudo systemctl enable recorder.service
sudo systemctl start recorder.service
