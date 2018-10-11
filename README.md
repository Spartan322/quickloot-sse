# quickloot-sse
[WIP] Skyrim: Special Edition port of [Quick Loot by himika](https://www.nexusmods.com/skyrim/mods/73096/).

This is only for the SKSE plugin portion of the mod, if all goes well the flash portion will not have to change.

Want to help out? Join us at https://discord.gg/gU9nNuf.

## Current state
 - Fixed memory addresses for latest Skyrim SE build
 - Loads container contents and shows them in console
 - **Help wanted**: calls to show/hide UI

## Development (current SKSE version: 2.0.10)
 - Download and install SKSE64 source
 - Clone this repository into src/skse64/
 - Add QuickLoot_SSE.vcxproj to skse64.sln
 - Should now be able to compile the dll

Note: does not yet work if the dll is installed using a mod manager tool.

## Contributing
 - Please do not modify the SKSE core (like the original author did).