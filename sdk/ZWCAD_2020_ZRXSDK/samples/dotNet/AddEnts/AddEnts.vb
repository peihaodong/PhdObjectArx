Imports ZwSoft.ZwCAD.ApplicationServices
Imports ZwSoft.ZwCAD.Runtime
Imports ZwSoft.ZwCAD.DatabaseServices
Imports ZwSoft.ZwCAD.Geometry

Namespace zwcadNet
    Public Class AddEnts
        <CommandMethod("AddEnts")> Public Sub AddEnts()
            'Get the current document and database
            Dim zwDoc As Document = Application.DocumentManager.MdiActiveDocument
            Dim zwDB As Database = zwDoc.Database
            ' Start a transaction
            Using zwTran As Transaction = zwDB.TransactionManager.StartTransaction
                'Open the Block table for read
                Dim zwBLT As BlockTable= zwTran.GetObject(zwDB.BlockTableId, OpenMode.ForRead)
                '  Open the Block table record Model space for write
                Dim zwBLTR As BlockTableRecord = zwTran.GetObject(zwBLT(BlockTableRecord.ModelSpace), OpenMode.ForWrite)

                ' Create a circle that is at 2,3 with a radius of 10 
                Dim zwCircle As Circle = New Circle
                zwCircle.Center = New Point3d(2, 3, 0)
                zwCircle.Radius = 10
                'Add the new object to the block table record
                zwBLTR.AppendEntity(zwCircle)
                'Add the new object to the transaction
                zwTran.AddNewlyCreatedDBObject(zwCircle, True)

                'Create a line that starts at 0, 0 and ends at 10, 10
                Dim zwLine As Line = New Line(New Point3d(0, 0, 0), New Point3d(10, 10, 0))
                'Set the line to the color 1
                zwLine.ColorIndex = 1
                'Add the new object to the block table record
                zwBLTR.AppendEntity(zwLine)
                'Add the new object to the transaction
                zwTran.AddNewlyCreatedDBObject(zwLine, True)

                'Save the new object to the database
                zwTran.Commit()
                'Dispose of the transaction
            End Using
            'Zoom to the extents or limits of the drawing
            zwDoc.SendStringToExecute("_zoom e ", True, False, False)
        End Sub

    End Class

End Namespace
