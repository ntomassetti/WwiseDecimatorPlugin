# WwiseDecimatorPlugin
Wwise Decimator Effect Plugin

A free Wwise plugin that implements a simple decimation algorithim from the archives of MusicDSP.org. Profiles CPU usage on average of less than 0.1% similar to other Wwise plugins.  Feel free to suggest or improve upon it.

Quick Start Guide:

1. You will need to set the properties of each solution to point to the Wwise SDK include folder.

2. In the Decimator solution (not FX) you need to make sure that the Linker dependency folders are correctly pointing to where the DecimatorFX.lib file will generate to as it is dependent upon it.  I need to make a global path for it but haven't gottan around to it.

3. in WwiseVersion\SDK\include\AK\Plugin copy the DecimatorFactory.h file so that the solutions link properly.


Building and Using the Solutions:

Make sure DecimatorFX has generated the .lib file before Decimator.dll is built otherwise it will fail.  When generated, copy the Decimator.dll and .xml files to your plugins folder of your Wwise installation.  Load up wwise and it should be in your effects plugin selection.
