#pragma once
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include <string.h>




namespace CppCLR_WinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Runtime::InteropServices;
	using namespace System::Type;

	using namespace std;
	using namespace cv;

	VideoCapture capture;
	Mat frame;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class ANPR : public System::Windows::Forms::Form
	{
	public:
		ANPR(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~ANPR()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  mainTabControl;
	private: System::Windows::Forms::TabPage^  addLicensePlateTabPage;
	private: System::Windows::Forms::TabPage^  parkingINTabPage;

	protected:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  LicencePlateNumbertxt;
	private: System::Windows::Forms::Button^  addLicencePlatebtn;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::Button^  Clickbtn;
	private: System::Windows::Forms::TrackBar^  trackBar;
	private: System::Windows::Forms::Timer^  timer;
	private: System::ComponentModel::IContainer^  components;



	private:
		
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->mainTabControl = (gcnew System::Windows::Forms::TabControl());
			this->addLicensePlateTabPage = (gcnew System::Windows::Forms::TabPage());
			this->addLicencePlatebtn = (gcnew System::Windows::Forms::Button());
			this->LicencePlateNumbertxt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->parkingINTabPage = (gcnew System::Windows::Forms::TabPage());
			this->trackBar = (gcnew System::Windows::Forms::TrackBar());
			this->Clickbtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->mainTabControl->SuspendLayout();
			this->addLicensePlateTabPage->SuspendLayout();
			this->parkingINTabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// mainTabControl
			// 
			this->mainTabControl->Controls->Add(this->addLicensePlateTabPage);
			this->mainTabControl->Controls->Add(this->parkingINTabPage);
			this->mainTabControl->Location = System::Drawing::Point(13, 13);
			this->mainTabControl->Name = L"mainTabControl";
			this->mainTabControl->SelectedIndex = 0;
			this->mainTabControl->Size = System::Drawing::Size(362, 346);
			this->mainTabControl->TabIndex = 0;
			// 
			// addLicensePlateTabPage
			// 
			this->addLicensePlateTabPage->Controls->Add(this->addLicencePlatebtn);
			this->addLicensePlateTabPage->Controls->Add(this->LicencePlateNumbertxt);
			this->addLicensePlateTabPage->Controls->Add(this->label1);
			this->addLicensePlateTabPage->Location = System::Drawing::Point(4, 22);
			this->addLicensePlateTabPage->Name = L"addLicensePlateTabPage";
			this->addLicensePlateTabPage->Padding = System::Windows::Forms::Padding(3);
			this->addLicensePlateTabPage->Size = System::Drawing::Size(354, 320);
			this->addLicensePlateTabPage->TabIndex = 0;
			this->addLicensePlateTabPage->Text = L"Add License Plate";
			this->addLicensePlateTabPage->UseVisualStyleBackColor = true;
			// 
			// addLicencePlatebtn
			// 
			this->addLicencePlatebtn->Location = System::Drawing::Point(136, 34);
			this->addLicencePlatebtn->Name = L"addLicencePlatebtn";
			this->addLicencePlatebtn->Size = System::Drawing::Size(111, 23);
			this->addLicencePlatebtn->TabIndex = 2;
			this->addLicencePlatebtn->Text = L"Add License Plate";
			this->addLicencePlatebtn->UseVisualStyleBackColor = true;
			this->addLicencePlatebtn->Click += gcnew System::EventHandler(this, &ANPR::addLicencePlatebtn_Click);
			// 
			// LicencePlateNumbertxt
			// 
			this->LicencePlateNumbertxt->Location = System::Drawing::Point(136, 7);
			this->LicencePlateNumbertxt->Name = L"LicencePlateNumbertxt";
			this->LicencePlateNumbertxt->Size = System::Drawing::Size(154, 20);
			this->LicencePlateNumbertxt->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Licence Plate Number";
			// 
			// parkingINTabPage
			// 
			this->parkingINTabPage->Controls->Add(this->trackBar);
			this->parkingINTabPage->Controls->Add(this->Clickbtn);
			this->parkingINTabPage->Controls->Add(this->pictureBox);
			this->parkingINTabPage->Location = System::Drawing::Point(4, 22);
			this->parkingINTabPage->Name = L"parkingINTabPage";
			this->parkingINTabPage->Padding = System::Windows::Forms::Padding(3);
			this->parkingINTabPage->Size = System::Drawing::Size(354, 320);
			this->parkingINTabPage->TabIndex = 1;
			this->parkingINTabPage->Text = L"Parking In";
			this->parkingINTabPage->UseVisualStyleBackColor = true;
			// 
			// trackBar
			// 
			this->trackBar->Location = System::Drawing::Point(10, 237);
			this->trackBar->Name = L"trackBar";
			this->trackBar->Size = System::Drawing::Size(104, 45);
			this->trackBar->TabIndex = 2;
			// 
			// Clickbtn
			// 
			this->Clickbtn->Location = System::Drawing::Point(130, 259);
			this->Clickbtn->Name = L"Clickbtn";
			this->Clickbtn->Size = System::Drawing::Size(75, 23);
			this->Clickbtn->TabIndex = 1;
			this->Clickbtn->Text = L"Start";
			this->Clickbtn->UseVisualStyleBackColor = true;
			this->Clickbtn->Click += gcnew System::EventHandler(this, &ANPR::Clickbtn_Click);
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(7, 7);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(341, 224);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			// 
			// timer
			// 
			this->timer->Interval = 30;
			this->timer->Tick += gcnew System::EventHandler(this, &ANPR::timer_Tick);
			// 
			// ANPR
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(387, 371);
			this->Controls->Add(this->mainTabControl);
			this->Name = L"ANPR";
			this->Text = L"ANPR";
			this->Load += gcnew System::EventHandler(this, &ANPR::ANPR_Load);
			this->mainTabControl->ResumeLayout(false);
			this->addLicensePlateTabPage->ResumeLayout(false);
			this->addLicensePlateTabPage->PerformLayout();
			this->parkingINTabPage->ResumeLayout(false);
			this->parkingINTabPage->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ANPR_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void addLicencePlatebtn_Click(System::Object^  sender, System::EventArgs^  e) {
		System::String^ connString = "Data Source = DESKTOP-S4CCM9R\\SQLEXPRESS; Initial Catalog = ANPR; Integrated Security=true";
		SqlConnection^ connection;
		connection = gcnew SqlConnection(connString);

		SqlCommand^ cmd;

		System::String^ licensePlateNumber = this->LicencePlateNumbertxt->Text;

		try
		{
			connection->Open();
			cmd = gcnew SqlCommand();
			cmd->Connection = connection;
			cmd->CommandText = "AddLicensePlate";
			cmd->CommandType = CommandType::StoredProcedure;
			cmd->Parameters->Add("@LicensePlateNumber", SqlDbType::NVarChar)->Value = licensePlateNumber;
			cmd->ExecuteNonQuery();
			//MessageBox::Show(licensePlateNumber + " sucessfully added.", "Sucessfully Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (System::Exception^ ex)
		{
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}
	}

	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
		capture.read(frame);
		frame = finder(frame, "haarcascade_frontalface_alt.xml");

		System::Drawing::Graphics^ graphics2 = pictureBox->CreateGraphics();
		System::IntPtr ptr2(frame.ptr());
		System::Drawing::Bitmap^ b2 = gcnew System::Drawing::Bitmap(frame.cols,
			frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
		System::Drawing::RectangleF rect2(0, 0, pictureBox->Width, pictureBox->Height);
		graphics2->DrawImage(b2, rect2);
	}
	
	private: Mat finder(Mat img, string cass)
	{

		resize(img, img, cv::Size(600, 400));
		// Load cascate classifier placed in sulution folder
		CascadeClassifier detector;
		string cascadeName = cass;
		bool loaded = detector.load(cascadeName);
		// Parameters of detectMultiscale Cascade Classifier
		int groundThreshold = 2;
		double scaleStep = 1.1;
		cv::Size minimalObjectSize(100, 100);
		cv::Size maximalObjectSize(200, 200);
		// Vector of returned found
		vector<Rect> found;
		// Convert input to greyscale 
		Mat image_grey;
		cvtColor(img, image_grey, CV_BGR2GRAY);
		// why not
		found.clear();
		// Detect found
		detector.detectMultiScale(image_grey, found, scaleStep, groundThreshold, 0 | 2, minimalObjectSize, maximalObjectSize);
		// Draw circles on the detected found
		for (int i = 0; i < found.size(); i++)
		{
			cv::Point pt1(found[i].x, found[i].y); // Display detected faces on main window - live stream from camera
			cv::Point pt2((found[i].x + found[i].height), (found[i].y + found[i].width));
			rectangle(img, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);

		}


		return img;


	}

	/*
	private: std::byte * matToBytes(Mat image)
	{
		int size = image.total() * image.elemSize();
		std::byte * bytes = new std::byte[size];  // you will have to delete[] that later
		std::memcpy(bytes, image.data, size * sizeof(std::byte));
	}
	*/
	private: System::Void Clickbtn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (Clickbtn->Text == "Start")
		{
			trackBar->Minimum = 0;
			trackBar->Maximum = 1000;
			Clickbtn->Text = "Stop";

			capture.open(0);

			if (!capture.isOpened())  // check if we succeeded
				MessageBox::Show("Video Capture failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			else
			{
				timer->Start();
			}
			
		}
		else 
		{
			capture.release();
			timer->Stop();
			
			/*
			System::String^ connString = "Data Source = DESKTOP-S4CCM9R\\SQLEXPRESS; Initial Catalog = ANPR; Integrated Security=true";
			SqlConnection^ connection;
			connection = gcnew SqlConnection(connString);

			SqlCommand^ cmd;

			System::String^ licensePlateNumber = this->LicencePlateNumbertxt->Text;

			try
			{
				connection->Open();
				cmd = gcnew SqlCommand();
				cmd->Connection = connection;
				cmd->CommandText = "AddParkingIn";
				cmd->CommandType = CommandType::StoredProcedure;
				cmd->Parameters->Add("@LicensePlateID", SqlDbType::Int)->Value = 2;
				
				Image^ img = pictureBox->Image;
				ImageConverter converter;
				int as = 10;
				Type^ t = Type::typeof(as);
				byte arr[] = (byte)converter.ConvertTo(img, std::typeof(byte));
				
				// int size = (int)frame.total() * frame.channels();
				// std::byte[] data = new byte[size];
				// frame.get(0, 0, data); // Gets all pixels
				

				//cmd->Parameters->Add("@ParkingInImage", SqlDbType::VarBinary)->Value = arr;

				
			//	cmd->ExecuteNonQuery();
				//MessageBox::Show(licensePlateNumber + " sucessfully added.", "Sucessfully Added", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			catch (System::Exception^ ex)
			{
				MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
			}
			*/
			Clickbtn->Text = "Start";
		}

		
	}
};
}
