Imports ZwSoft.ZwCAD.Runtime
Imports ZwSoft.ZwCAD.ApplicationServices
Imports ZwSoft.ZwCAD.DatabaseServices
Imports ZwSoft.ZwCAD.EditorInput

Public Class EventsWatcher
    Private zwDoc As Document = Application.DocumentManager.MdiActiveDocument
    <CommandMethod("AddEvent")> Public Sub AddEvent()
        'Register the ImpliedSelectionChanged event
        'Add the event handler to watch for when the PickFirst selection set is changed
        AddHandler zwDoc.ImpliedSelectionChanged, AddressOf ImpliedSelectionChanged
    End Sub
    <CommandMethod("RemoveEvent")> Public Sub RemoveEvent()
        'Remove the ImpliedSelectionChanged event
        RemoveHandler zwDoc.ImpliedSelectionChanged, AddressOf ImpliedSelectionChanged
    End Sub
    Public Sub ImpliedSelectionChanged(ByVal sender As Object, ByVal e As EventArgs)
        'Get the current document
        Dim zwDocEd As Editor = zwDoc.Editor
        'Get the PickFirst selection set
        Dim zwSSPrompt As PromptSelectionResult
        zwSSPrompt = zwDocEd.SelectImplied()
        'If the prompt status is OK, objects were selected before
        If zwSSPrompt.Status = PromptStatus.OK Then
            Dim CurrentSS As SelectionSet = zwSSPrompt.Value
            MsgBox(CurrentSS.Count)
        End If
    End Sub
End Class
