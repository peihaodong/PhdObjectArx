Imports ZwSoft.ZwCAD.Runtime
Imports ZwSoft.ZwCAD.EditorInput
Imports ZwSoft.ZwCAD.ApplicationServices

Public Class HelloWorld
    'Defines a command named HelloWorld
    <CommandMethod("HelloWorld")> _
    Public Sub HelloWorld()
        'Get the current document
        Dim zwEd As Editor = Application.DocumentManager.MdiActiveDocument.Editor
        'Write the following message to command window
        zwEd.WriteMessage("Hello World")
    End Sub
End Class
