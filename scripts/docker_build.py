#!/usr/bin/env python

# ------------------------------------------------------------------------------
# Bash script to build cpp-ethereum within TravisCI.
#
# The documentation for cpp-ethereum is hosted at http://cpp-ethereum.org
#
# ------------------------------------------------------------------------------
# This file is part of cpp-ethereum.
#
# cpp-ethereum is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# cpp-ethereum is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>
#
# (c) 2016 cpp-ethereum contributors.
# ------------------------------------------------------------------------------
#
# Copyright (C) 2019-Present SKALE Labs

# This file is part of sgxwallet.

# sgxwallet is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published
# by the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# sgxwallet is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.

# You should have received a copy of the GNU Affero General Public License
# along with sgxwallet.  If not, see <https://www.gnu.org/licenses/>.
#
#    @file  docker_build.py
#    @author Stan Kladko
#    @date 2020
#

import sys, os, subprocess, time
os.chdir("..")
topDir = os.getcwd() + "/sgxwallet"
BRANCH = sys.argv[1];
DOCKER_FILE_NAME = sys.argv[2];
IMAGE_NAME = sys.argv[3];
if (BRANCH == "develop") :
   TAG_POSTFIX = "latest";
else :
    TAG_POSTFIX = "latest_commit"


FULL_IMAGE_NAME = "skalenetwork/" + IMAGE_NAME +":" + TAG_POSTFIX;

print("Starting build for branch " + BRANCH, flush=True)

assert subprocess.call(["pwd"]) == 0;

assert subprocess.call(["docker", "build", topDir, "--file", topDir + "/" + DOCKER_FILE_NAME, "--tag",
                                              FULL_IMAGE_NAME]) == 0;

