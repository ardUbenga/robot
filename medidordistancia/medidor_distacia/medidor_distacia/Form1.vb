Imports System.IO
Imports System.IO.Ports
Imports System.Threading

Public Class Form1
    Shared _continue As Boolean
    Shared _serialPort As SerialPort
    Private Sub Form1_Disposed(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Disposed
        SerialPort1.Close()
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        SerialPort1.PortName = "com4"
        SerialPort1.BaudRate = "9600"
        SerialPort1.DataBits = "8"
        SerialPort1.Parity = Parity.None
        SerialPort1.StopBits = StopBits.One
        SerialPort1.Handshake = Handshake.None
        SerialPort1.Encoding = System.Text.Encoding.Default
        SerialPort1.Open()
        CheckForIllegalCrossThreadCalls = False ' Esta línea no le gusta mucho a los programadores,
        ' pero aquí la ponemos para que funcione el Label1

    End Sub

    Private Sub SerialPort1_DataReceived(ByVal sender As Object, ByVal e As System.IO.Ports.SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived
        Dim distancia As String
        distancia = SerialPort1.ReadLine 
        If distancia < 20 Then
            TextBox1.ForeColor = Color.Red
        Else : TextBox1.ForeColor = Color.Black
        End If
        TextBox1.Text = distancia

    End Sub
End Class
