Module Solution
    Private __iptstr() As String
    Private __iptlen As Long = 0
    Private __iptptr As Long = 0
    Function InputBox(str As String) As String
        If __iptptr = __iptlen Then
            __iptstr = System.Console.ReadLine().Split(New Char() {" "c})
            __iptptr = 0
            __iptlen = __iptstr.LongLength
        End If
        __iptptr = __iptptr + 1
        Return __iptstr(__iptptr - 1)
    End Function
    Sub Print(str As Object)
        System.Console.WriteLine(str)
    End Sub
    Sub Printx(str As Object)
        System.Console.Write(str)
    End Sub
    Sub Main()
        Dim a As Long
        Dim b As Long
        a = Val(InputBox(""))
        b = Val(InputBox(""))
        Print (a + b)
    End Sub
End Module