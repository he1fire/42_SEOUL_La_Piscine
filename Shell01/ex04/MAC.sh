#!/bin/bash
ifconfig -a link | grep ether | tr -d '[:blank:]' | sed 's/ether//g'
