#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <vtkVersion.h>
#include <vtkPolyData.h>
#if VTK_MAJOR_VERSION <= 5
#include <vtkPLOT3DReader.h>
#else
#include <vtkMultiBlockPLOT3DReader.h>
#include <vtkMultiBlockDataSet.h>
#endif
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include "QVTKWidget.h"
#include "OpenMesh\Core\IO\MeshIO.hh"
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <vtkStructuredGridGeometryFilter.h>
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkSphereSource.h"
#include <vtkOBJReader.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <vtkProperty.h>
#include <vtkPolyData.h>
#include <vtkPLYReader.h>
#include <vtkSimplePointsReader.h>
#include <vtkSTLReader.h>
#include <vtkParticleReader.h>
#include <vtkSmartPointer.h>
#include <vtkPlot3DMetaReader.h>
#include "vtkPolyVertex.h"
#include "vtkUnstructuredGrid.h"
#include "vtkDecimatePro.h"
#include "vtkPolyDataMapper.h"
#include "vtkPolyDataNormals.h"
#include "vtkSmoothPolyDataFilter.h"
#include "vtkPolyDataReader.h"
typedef OpenMesh::TriMesh_ArrayKernelT<> MyMesh;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void loadFile(const QString &fileName);
       void saveFile(const QString &fileName);
       QString openfilename;
	   void readobj(char*  ch);
	   void readply(char*  ch);
	   void readxyz(char*  ch);
	   void readstl(char*  ch);

    ~MainWindow();
    
private slots:
    void on_actionRead_triggered();

    void on_actionSave_triggered();

   

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
