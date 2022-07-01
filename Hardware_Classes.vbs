' References
' https://stackoverflow.com/questions/2198810/creating-and-writing-lines-to-a-file
' https://docs.microsoft.com/en-us/windows/win32/cimwin32prov/win32-processor
' https://docs.microsoft.com/en-us/windows/win32/cimwin32prov/win32-videocontroller

Set objFSO=CreateObject("Scripting.FileSystemObject")
outFile="Hardware_Classes.txt"
Set objFile = objFSO.CreateTextFile(outFile,True) 

strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
 & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set OS = objWMIService.ExecQuery("Select * from Win32_OperatingSystem")
For Each obj in OS
  objFile.Write obj.CSName & vbCrLf 'computer name
  'objFile.Write "Operating System" & vbCrLf
  objFile.Write obj.Caption & vbCrLf 'operating system
  objFile.Write obj.OSArchitecture & vbCrLf 'architecture
Next

Set Processors = objWMIService.ExecQuery("Select * from Win32_Processor")
For Each obj in Processors
  objFile.Write obj.Manufacturer & vbCrLf 'Manufacturer
  objFile.Write obj.Name & vbCrLf 'Processor Name
  objFile.Write obj.NumberOfCores & vbCrLf 'NumberOfCores
  objFile.Write obj.MaxClockSpeed & "MHz" & vbCrLf 'MaximumClockSpeed
Next

Set VideoController = objWMIService.ExecQuery("Select * from Win32_VideoController")
For Each objItem in VideoController
  objFile.Write "Accelerator Capabilities: " & objItem.AcceleratorCapabilities & vbCrLf
  objFile.Write "Adapter Compatibility: " & objItem.AdapterCompatibility  & vbCrLf
  objFile.Write "Adapter DAC Type: " & objItem.AdapterDACType  & vbCrLf
  objFile.Write "Adapter RAM: " & objItem.AdapterRAM  & vbCrLf
  objFile.Write "Availability: " & objItem.Availability  & vbCrLf
  objFile.Write "Capability Descriptions: " & objItem.CapabilityDescriptions  & vbCrLf
  objFile.Write "Caption: " & objItem.Caption  & vbCrLf
  objFile.Write "Color Table Entries: " & objItem.ColorTableEntries  & vbCrLf
  objFile.Write "Configuration Manager Error Code: " & objItem.ConfigManagerErrorCode  & vbCrLf
  objFile.Write "Configuration Manager User Configuration: " & objItem.ConfigManagerUserConfig  & vbCrLf
  objFile.Write "Creation Class Name: " & objItem.CreationClassName  & vbCrLf
  objFile.Write "Current Bits Per Pixel: " & objItem.CurrentBitsPerPixel  & vbCrLf
  objFile.Write "Current Horizontal Resolution: " & objItem.CurrentHorizontalResolution  & vbCrLf
  objFile.Write "Current Number Of Colors: " & objItem.CurrentNumberOfColors  & vbCrLf
  objFile.Write "Current Number Of Columns: " & objItem.CurrentNumberOfColumns  & vbCrLf
  objFile.Write "Current Number Of Rows: " & objItem.CurrentNumberOfRows  & vbCrLf
  objFile.Write "Current Refresh Rate: " & objItem.CurrentRefreshRate  & vbCrLf
  objFile.Write "Current Scan Mode: " & objItem.CurrentScanMode  & vbCrLf
  objFile.Write "Current Vertical Resolution: " & objItem.CurrentVerticalResolution  & vbCrLf
  objFile.Write "Description: " & objItem.Description  & vbCrLf
  objFile.Write "Device ID: " & objItem.DeviceID  & vbCrLf
  objFile.Write "Device Specific Pens: " & objItem.DeviceSpecificPens  & vbCrLf
  objFile.Write "Dither Type: " & objItem.DitherType  & vbCrLf
  objFile.Write "Driver Date: " & objItem.DriverDate  & vbCrLf
  objFile.Write "Driver Version: " & objItem.DriverVersion  & vbCrLf
  objFile.Write "Error Cleared: " & objItem.ErrorCleared  & vbCrLf
  objFile.Write "Error Description: " & objItem.ErrorDescription  & vbCrLf
  objFile.Write "ICM Intent: " & objItem.ICMIntent  & vbCrLf
  objFile.Write "ICM Method: " & objItem.ICMMethod  & vbCrLf
  objFile.Write "Inf File Name: " & objItem.InfFilename  & vbCrLf
  objFile.Write "Inf Section: " & objItem.InfSection  & vbCrLf
  objFile.Write "Installation Date: " & objItem.InstallDate  & vbCrLf
  objFile.Write "Installed Display Drivers: " & objItem.InstalledDisplayDrivers  & vbCrLf
  objFile.Write "Last Error Code: " & objItem.LastErrorCode  & vbCrLf
  objFile.Write "Maximum Memory Supported: " & objItem.MaxMemorySupported  & vbCrLf
  objFile.Write "Maximum Number Controlled: " & objItem.MaxNumberControlled  & vbCrLf
  objFile.Write "Maximum Refresh Rate: " & objItem.MaxRefreshRate  & vbCrLf
  objFile.Write "Minimum Refresh Rate: " & objItem.MinRefreshRate  & vbCrLf
  objFile.Write "Monochrome: " & objItem.Monochrome  & vbCrLf
  objFile.Write "Name: " & objItem.Name  & vbCrLf
  objFile.Write "Number Of Color Planes: " & objItem.NumberOfColorPlanes  & vbCrLf
  objFile.Write "Number Of Video Pages: " & objItem.NumberOfVideoPages  & vbCrLf
  objFile.Write "PNP Device ID: " & objItem.PNPDeviceID  & vbCrLf
  objFile.Write "Power Management Capabilities: " & objItem.PowerManagementCapabilities  & vbCrLf
  objFile.Write "Power Management Supported: " & objItem.PowerManagementSupported  & vbCrLf
  objFile.Write "Protocol Supported: " & objItem.ProtocolSupported  & vbCrLf
  objFile.Write "Reserved System Palette Entries: " & objItem.ReservedSystemPaletteEntries  & vbCrLf
  objFile.Write "Specification Version: " & objItem.SpecificationVersion  & vbCrLf
  objFile.Write "Status: " & objItem.Status  & vbCrLf
  objFile.Write "Status Information: " & objItem.StatusInfo  & vbCrLf
  objFile.Write "System Creation Class Name: " & objItem.SystemCreationClassName  & vbCrLf
  objFile.Write "System Name: " & objItem.SystemName  & vbCrLf
  objFile.Write "System Palette Entries: " & objItem.SystemPaletteEntries  & vbCrLf
  objFile.Write "Time Of Last Reset: " & objItem.TimeOfLastReset  & vbCrLf
  objFile.Write "Video Architecture: " & objItem.VideoArchitecture  & vbCrLf
  objFile.Write "Video Memory Type: " & objItem.VideoMemoryType  & vbCrLf
  objFile.Write "Video Mode: " & objItem.VideoMode  & vbCrLf
  objFile.Write "Video Mode Description: " & objItem.VideoModeDescription  & vbCrLf
  objFile.Write "Video Processor: " & objItem.VideoProcessor  & vbCrLf
Next

objFile.Close