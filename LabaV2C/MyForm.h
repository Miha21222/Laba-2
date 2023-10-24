#include <Winsock2.h>
#include <iostream>
#pragma comment(lib, "ws2_32.lib")

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Text;

namespace LabaV2C {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		UdpClient^ udpClient;
		int serverPort = 12345;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
		   String^ serverIPAddress = "127.0.0.1";
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			udpClient = gcnew UdpClient();
		}

	private:
		void SendMessage(String^ message)
		{
			array<Byte>^ sendBytes = Encoding::ASCII->GetBytes(message);
			udpClient->Send(sendBytes, sendBytes->Length, serverIPAddress, serverPort);
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		void SendMessageButton_Click(Object^ sender, EventArgs^ e)
		{
			String^ messageToSend = "������, ������!";
			SendMessage(messageToSend);
		}

	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(460, 317);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 53);
			this->button1->TabIndex = 1;
			this->button1->Text = L"���������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(104, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(416, 55);
			this->label1->TabIndex = 2;
			this->label1->Text = L"������� �������";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(12, 240);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(575, 38);
			this->textBox1->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 317);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 53);
			this->button2->TabIndex = 4;
			this->button2->Text = L"������ ������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(599, 399);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		String^ one = "������ ��������� ������: \n\nclear display : <����> - ������� ����� � ��������� ��� ��������� ������ \n\ndraw pixel : <�0> <y0> <����> - ������������� ������� ���������������� ����� � ������������ �0, �0 \n\ndraw rectangle : <�0> <y0> <w> <h> <����> - ������ ������������� ���������������� �����, �� ��������� �0, �0 �� ��������� �1 �1 \n\nfill rectangle : <�0> <y0> <w> <h> <����> - ������ ����������� ������������� ���������������� �����, �� ��������� �0, �0 �� ��������� �1 �1 \n\ndraw ellipse : <�0> <y0> <������ �> <������ �> <����> - ������ ������ ���������������� �����, �� ��������� �0, �0 �� ��������� �1 �1 \n\nfill ellipse : <�0> <y0> <������ �> <������ �> <����> - ������ ����������� ������ ���������������� �����, �� ��������� �0, �0 �� ��������� �1 �1 \n\n draw circle : <x0> <y0> <radius> <color> - ������ ���� � ���������� ��������, ���������� ������������ � ������.\n\nfill circle : <x0> <y0> <color> ������ ����������� ���� � ���������� ��������, ���������� ������������ � ������.\n\n draw rounded rectangle : <x0> <y0> <w> <h> <radius> <color> - ������ ������������� � ������������ ������ � ��������� ������������, ������, ������� � ������.\n\n fill rounded rectangle : <x0> <y0> <w> <h> <radius> <color> - ������ ����������� ������������� � ������������ ������ � ��������� ��������� �����������, ������, �������, �������� � ������.\n\ndraw text <x0> <y0> <color> <font_number> <length> <text> : ����� ����� � ��������� �����������, ������, �������, ������ � ����� �������\n\ndraw image : <x0> <y0> <width> <height> <color> : ������ �����-�� ����������� � ���������� ������������, ������, ������� � ������ (��������� ������ ������ ����� �������������� �� ������� ��� �� ������ �����, ����� � ������)\n";
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ buf_com = textBox1->Text;
		SendMessage(buf_com);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(one, "������ ������ :)", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	};
}
