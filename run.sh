#!/usr/bin/env bash

VERSION=$(date +%s)

docker build . -t enigma:${VERSION} && \
	docker run --rm -i -t enigma:${VERSION}
