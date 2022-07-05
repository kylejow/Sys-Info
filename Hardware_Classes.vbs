' References
' https://stackoverflow.com/questions/2198810/creating-and-writing-lines-to-a-file
' https://docs.microsoft.com/en-us/windows/win32/cimwin32prov/win32-processor
' https://docs.microsoft.com/en-us/windows/win32/cimwin32prov/win32-videocontroller
' https://docs.microsoft.com/en-us/windows/win32/cimwin32prov/win32-baseboard

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
  objFile.Write obj.TotalVisibleMemorySize/1048576 & " GB" & vbCrLf 'ram
Next

Set Processors = objWMIService.ExecQuery("Select * from Win32_Processor")
For Each obj in Processors
  objFile.Write obj.Manufacturer & vbCrLf 'Manufacturer
  objFile.Write obj.Name & vbCrLf 'Processor Name
  objFile.Write obj.NumberOfCores & vbCrLf 'NumberOfCores
  objFile.Write obj.MaxClockSpeed & " MHz" & vbCrLf 'MaximumClockSpeed
Next

Set VideoController = objWMIService.ExecQuery("Select * from Win32_VideoController")
objFile.Write VideoController.Count & vbCrLf 'account for multiple gpu
For Each obj in VideoController
  objFile.Write obj.Name & vbCrLf 'gpu name
  'objFile.Write obj.AdapterRAM  & vbCrLf 'vram in bytes stored as uint32 - cannot display above 4gb
Next

Set BaseBoard = objWMIService.ExecQuery("Select * from Win32_BaseBoard") 
For Each obj in BaseBoard 
  objFile.Write obj.Manufacturer & vbCrLf 'Manufacturer
  objFile.Write obj.Product & vbCrLf 'name
Next

objFile.Close