#include "mainwindow.h"
#include "ui_mainwindow.h"
//actor->GetProperty()->SetRepresentationToPoints()
//actor->GetProperty()->SetRepresentationToWireframe()
//actor->GetProperty()->SetRepresentationToSurface()
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionRead_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("open file"), " ",  tr("file(*.obj *.xyz *.ply *.stl)"));
	

QByteArray ba = fileName.toLatin1();    

        if (!fileName.isEmpty())
          {  loadFile(fileName);
		   if(fileName.indexOf(".obj")!= -1)
		   {readobj(ba.data());}
		   if(fileName.indexOf(".ply")!= -1)
		   {readply(ba.data());}
		   if(fileName.indexOf(".xyz")!= -1)
		   {readxyz(ba.data());}
		   if(fileName.indexOf(".stl")!= -1)
		   {readstl(ba.data());}
		   
		   }
		
             

        
		
		
   openfilename=fileName;

}


void MainWindow::loadFile(const QString &fileName)
//! [42] //! [43]
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;

    }
}

void MainWindow::saveFile(const QString &fileName)
{
     QFile file(fileName);
     if(!file.open(QFile::WriteOnly | QFile::Text))
     {
         QMessageBox::warning(this, tr("Application"),
                              tr("Cannot write file %1:\n%2.")
                              .arg(QDir::toNativeSeparators(fileName), file.errorString()));
         return;
     }

}


void MainWindow::on_actionSave_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this, tr("save file"), " ",  tr("file(*.obj *.xyz *.ply *.stl)"));
	MyMesh mesh;
	std::string s = openfilename.toStdString();
	if (!OpenMesh::IO::read_mesh(mesh,s))
	{
std::cerr << "read error\n";
exit(1);
    }
	if (!OpenMesh::IO::write_mesh(mesh, filename.toStdString())) 
{
std::cerr << "write error\n";


}
}


 void MainWindow::readobj(char*  ch)
 {
	  vtkSmartPointer<vtkOBJReader> reader =
    vtkSmartPointer<vtkOBJReader>::New();
  reader->SetFileName(ch);
  reader->Update();
 
  // Visualize
  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(reader->GetOutputPort());
 
  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
 
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(actor);
  renderer->SetBackground(.0, .0, .0); // Background color black
 
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
 
vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
    ui->qvtkWidget->SetRenderWindow(renderWindow);
 
  renderWindowInteractor->Start();
  ui->qvtkWidget->show();
 };

 void MainWindow::readply(char*  ch)
 {
	
 
 
  vtkSmartPointer<vtkPLYReader> reader =
    vtkSmartPointer<vtkPLYReader>::New();
  reader->SetFileName (ch);
 
  // Visualize
  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(reader->GetOutputPort());
 
  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
 
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();

  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  
 
  renderer->AddActor(actor);
  renderer->SetBackground(.0,.0,.0); 
  ui->qvtkWidget->SetRenderWindow(renderWindow);
 
  renderWindowInteractor->Start();
  ui->qvtkWidget->show();

 
 


 }

  void MainWindow::readxyz(char*  ch)
 {  vtkSmartPointer<vtkSimplePointsReader> reader =
    vtkSmartPointer<vtkSimplePointsReader>::New();
  reader->SetFileName ( ch );
  reader->Update();
 
  // Visualize
  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(reader->GetOutputPort());
 
  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  actor->GetProperty()->SetPointSize(4);
 
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(actor);
  renderer->SetBackground(.0, .0, .0); 
 
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
 
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
	
  ui->qvtkWidget->SetRenderWindow(renderWindow);
 
  renderWindowInteractor->Start();
  ui->qvtkWidget->show();
  }

  void MainWindow::readstl(char*  ch)
  {vtkSmartPointer<vtkSTLReader> reader =
    vtkSmartPointer<vtkSTLReader>::New();
  reader->SetFileName(ch);
  reader->Update();
 
  // Visualize
  vtkSmartPointer<vtkPolyDataMapper> mapper =
    vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(reader->GetOutputPort());
 
  vtkSmartPointer<vtkActor> actor =
    vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);

 
  vtkSmartPointer<vtkRenderer> renderer =
    vtkSmartPointer<vtkRenderer>::New();
  vtkSmartPointer<vtkRenderWindow> renderWindow =
    vtkSmartPointer<vtkRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  
 
  renderWindowInteractor->Start();
  
 
  renderer->AddActor(actor);
  renderer->SetBackground(.0, .0, .0); // Background color green
   
   ui->qvtkWidget->SetRenderWindow(renderWindow);
  ui->qvtkWidget->show();
  
  }

  