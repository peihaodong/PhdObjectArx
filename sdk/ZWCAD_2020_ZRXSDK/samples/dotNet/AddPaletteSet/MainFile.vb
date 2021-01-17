Imports ZwSoft.ZwCAD.Runtime
Imports ZwSoft.ZwCAD.EditorInput
Imports ZwSoft.ZwCAD.DatabaseServices
Imports ZcadAp = ZwSoft.ZwCAD.ApplicationServices.Application
Imports ZwSoft.ZwCAD.ApplicationServices

Public Class MainFile
    Private m_MainBoard As Palette
    Private m_Palette As ZwSoft.ZwCAD.Windows.PaletteSet

    <CommandMethod("AddPalette", CommandFlags.Session + CommandFlags.Modal)> _
    Sub ZWCAD_PaletteSet()
        If m_Palette Is Nothing Then
            m_MainBoard = New Palette
            Dim prjName As String = "ZWCAD_PaletteSet"
            m_Palette = New ZwSoft.ZwCAD.Windows.PaletteSet(prjName)
            m_Palette.Add(prjName, m_MainBoard)
            m_Palette.Visible = True
        Else
            m_Palette.Visible = True
        End If
    End Sub

End Class
