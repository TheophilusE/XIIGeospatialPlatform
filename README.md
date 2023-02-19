# XII Geospatial Platform

This program enables users to view Geospatial information on economic activity in Syria through night lights capture. The program is built with my custom game engine, and offers interactive frame rates with 4K High Resolution captures compiled offline in GPU optimized format.

Night lights are commonly used to estimate economic activity in regions around the world. The trend in this activity overtime can be visualized through multiple night light captures on a certain region, that can be used to compare with previous collected data.

## How To Run

- Clone https://github.com/TheophilusE/XIIGeospatialPlatform

```bash
git clone https://github.com/TheophilusE/XIIGeospatialPlatform.git GeospatialPlatform
cd GeospatialPlatform/Binaries/GeospatialPlatform
./Launch MainScene.bat
```

> Note that this program is only available on Windows currently. An experimental D3D12 and Vulkan renderer is in the works, but does not fully work with all rendering features and have no unit tests.

# Tutorial

After running the program, these are shortcuts and general program utilities. Also ensure that you allow the engine through your public firewall, as it has IPC and Profiling enabled.

- Use the settings panel to pick which year and month.
- Use the adjust weighting to blend either between the previous month or the future month.
- F12 for screenshot
- F2 for debug console (use tab to see options and auto complete).
- F5 to show frames per second.
