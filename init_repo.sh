#!/bin/sh

# Copy the Sandbox plugin over to the plugin folder.
# This is a local-only plugin that you can do whatever you want in.
# It is not committed to the repo and it is the default plugin configured to load 
# (this means the repo won't work unless you run this script exactly once first).

BASEDIR=$(dirname "$0")
echo "$BASEDIR"
cd $BASEDIR

SANDBOX_PROJ_NAME="BEAMPROJ_Sandbox"
PLUGIN_SANDBOX_PATH="$(pwd)/Plugins/$SANDBOX_PROJ_NAME"
TEMPLATE_SANDBOX_PATH="$(pwd)/Templates/Plugins/$SANDBOX_PROJ_NAME"

mkdir -p "$PLUGIN_SANDBOX_PATH"
cp -r "$TEMPLATE_SANDBOX_PATH"/* "$PLUGIN_SANDBOX_PATH"
