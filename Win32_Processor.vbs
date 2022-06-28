' References
' https://docs.microsoft.com/en-us/windows/win32/cimwin32prov/win32-processor
' https://stackoverflow.com/questions/2198810/creating-and-writing-lines-to-a-file

Set objFSO=CreateObject("Scripting.FileSystemObject")
outFile="Win32_Processor.txt"
Set objFile = objFSO.CreateTextFile(outFile,True) 

strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
 & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set colOSes = objWMIService.ExecQuery("Select * from Win32_OperatingSystem")
For Each objOS in colOSes
  objFile.Write objOS.CSName & vbCrLf 'computer name
  'objFile.Write "Operating System" & vbCrLf
  objFile.Write objOS.Caption & vbCrLf 'operating system
  objFile.Write objOS.OSArchitecture & vbCrLf 'architecture
Next

'objFile.Write "Processors" & vbCrLf
Set colCompSys = objWMIService.ExecQuery("Select * from Win32_ComputerSystem")
For Each objCS in colCompSys
  'objFile.Write "  NumberOfProcessors: " & objCS.NumberOfProcessors & vbCrLf
  objFile.Write objCS.NumberOfLogicalProcessors & vbCrLf 'NumberOfLogicalProcessors
Next
Set colProcessors = objWMIService.ExecQuery("Select * from Win32_Processor")
For Each objProcessor in colProcessors
  objFile.Write objProcessor.Manufacturer & vbCrLf 'Manufacturer
  objFile.Write objProcessor.Name & vbCrLf 'Processor Name
  objFile.Write objProcessor.NumberOfCores & vbCrLf 'NumberOfCores
  objFile.Write objProcessor.MaxClockSpeed & vbCrLf 'MaximumClockSpeed
Next

objFile.Close