#!/usr/bin/env bash

VERSION=$(date +%m%d%y)

docker build . -t enigma:${VERSION} && \
	docker run --rm -i -t enigma:${VERSION}
