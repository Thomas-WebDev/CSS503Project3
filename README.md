# CSS503Project3
CSS 503 Project 3

<html>

<head>
<meta http-equiv=Content-Type content="text/html; charset=windows-1252">
<meta name=Generator content="Microsoft Word 15 (filtered)">

</head>

<body lang=EN-US>

<div class=WordSection1>

<p class=MsoNormal align=right style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:right;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>9 May 2018</span></p>

<p class=MsoNormal align=right style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:right;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>CSS503 Systems Programming</span></p>

<p class=MsoNormal align=right style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:right;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>Program 2 Report</span></p>

<p class=MsoNormal align=center style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:center;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal align=center style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:center;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>I. DOCUMENTATION</span></p>

<p class=MsoNormal align=center style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:center;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>&nbsp;</span></p>

<p class=paragraph style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.0in;margin-bottom:.0001pt;text-indent:-1.0in;vertical-align:baseline'>PURPOSE:     <span
style='font-family:"Cambria",serif;color:black'>In this programming assignment
you will design and implement your own core input and output functions of the
C/C++ standard I/O library, i.e., stdio.h.&nbsp;</span></p>

<p class=paragraph style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.0in;margin-bottom:.0001pt;text-indent:-1.0in;vertical-align:baseline'>&nbsp;</p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.0in;margin-bottom:.0001pt;text-indent:-1.0in;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>DESIGN:        The
general implementation details were provided by the function manual. Therefore,
it is only a matter of the manner of implementation. </span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.0in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>The function fflush
is meant to synchronizes an output stream with the actual file. This means that
is needs to write all data in the buffer then purge the buffer. Since the
buffer has been purged, the actual size of the buffer must also be set to 0.</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.0in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>The function fpurge’s
purpose is to clears an input/output stream buffer. It does this by calling the
bzero function which eases the data stored in the stream’s buffer.</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.0in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.0in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>The function fread
reads from the file. It does this by reading a set amount of data of an
indicated size and returns the number of data points read. It reads this data
into the buffer while the end of the buffer has not been reached. </span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.0in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>The function fwrite
writes to the file by moving the information stored in the buffer into the
stream’s buffer which then writes that information (that is stored in the
function) using the Unix system call into the file.</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.0in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>The function fclose
closes the file which seems simple but it must also delete the stream’s buffer
if the user has created one and check if it is possible to close the file (a
file must be opened before it can be closed).</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal align=center style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:center;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>II. SOURCE CODE</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>Please
find the following source code files uploaded along with the report.</span></p>

<p class=MsoListParagraphCxSpFirst style='margin-top:0in;margin-right:0in;
margin-bottom:0in;margin-left:.25in;margin-bottom:.0001pt;text-indent:-.25in;
line-height:normal'><span style='font-size:12.0pt;font-family:Symbol'>·<span
style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></span><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>driver.cpp</span></p>

<p class=MsoListParagraphCxSpMiddle style='margin-top:0in;margin-right:0in;
margin-bottom:0in;margin-left:.25in;margin-bottom:.0001pt;text-indent:-.25in;
line-height:normal'><span style='font-size:12.0pt;font-family:Symbol'>·<span
style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></span><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>eval.cpp</span></p>

<p class=MsoListParagraphCxSpMiddle style='margin-top:0in;margin-right:0in;
margin-bottom:0in;margin-left:.25in;margin-bottom:.0001pt;text-indent:-.25in;
line-height:normal'><span style='font-size:12.0pt;font-family:Symbol'>·<span
style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></span><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>stdio.h</span></p>

<p class=MsoListParagraphCxSpMiddle style='margin-top:0in;margin-right:0in;
margin-bottom:0in;margin-left:.25in;margin-bottom:.0001pt;text-indent:-.25in;
line-height:normal'><span style='font-size:12.0pt;font-family:Symbol'>·<span
style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></span><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>stdio.cpp</span></p>

<p class=MsoListParagraphCxSpLast style='margin-top:0in;margin-right:0in;
margin-bottom:0in;margin-left:.25in;margin-bottom:.0001pt;text-indent:-.25in;
line-height:normal'><span style='font-size:12.0pt;font-family:Symbol'>·<span
style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></span><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>compile.sh </span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal align=center style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:center;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>III. EXECUTION OUTPUT</span></p>

<p class=MsoNormal align=center style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:center;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal;vertical-align:baseline'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>Please
find the following source code files uploaded along with the report.</span></p>

<p class=MsoListParagraphCxSpFirst style='margin-top:0in;margin-right:0in;
margin-bottom:0in;margin-left:.25in;margin-bottom:.0001pt;text-indent:-.25in;
line-height:normal'><span style='font-size:12.0pt;font-family:Symbol'>·<span
style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></span><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>Project3DiffOutput.txt</span></p>

<p class=MsoListParagraphCxSpMiddle style='margin-top:0in;margin-right:0in;
margin-bottom:0in;margin-left:.25in;margin-bottom:.0001pt;text-indent:-.25in;
line-height:normal'><span style='font-size:12.0pt;font-family:Symbol'>·<span
style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></span><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>Project3Output.txt</span></p>

<p class=MsoListParagraphCxSpLast style='margin-top:0in;margin-right:0in;
margin-bottom:0in;margin-left:.25in;margin-bottom:.0001pt;text-indent:-.25in;
line-height:normal'><span style='font-size:12.0pt;font-family:Symbol'>·<span
style='font:7.0pt "Times New Roman"'>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></span><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>Project3Output2.txt</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal;vertical-align:baseline'><img width=624 height=416 id="Picture 1"
src="kehoek2_program3Report_files/image001.jpg"></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal;vertical-align:baseline'><img width=624 height=416 id="Picture 2"
src="kehoek2_program3Report_files/image002.jpg"></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal;vertical-align:baseline'><img width=624 height=416 id="Picture 3"
src="kehoek2_program3Report_files/image003.jpg"></p>

<p class=MsoNormal align=center style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:center;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal align=center style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:center;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>IV. DISCUSSION</span></p>

<p class=MsoNormal align=center style='margin-bottom:0in;margin-bottom:.0001pt;
text-align:center;line-height:normal'><span style='font-size:12.0pt;font-family:
"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>RESULTS
&amp; EFFECTIVENESS</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.5in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>My implementation
of the </span><span style='font-family:"Cambria",serif;color:black'>stdio.h did
not result in the correct output as a result, I shall use the output from the
assignment specifications and logic to draw conclusions from the output I
manage to get (see above)</span><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>.</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.5in;margin-bottom:.0001pt;text-indent:-1.5in;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>ANALYSIS:               It
is clear that the f- functions are less efficient at reading the example files
(Othello.txt and Hamlet.txt) in all cases.</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.5in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif;color:black'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.5in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif;color:black'>T</span><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>he fread and
fwrite functions are less efficient because they utilize a buffer rather than
repeated system calls. When using a buffer, one store a large portion of the
data in an easily accessible location (in a buffer). This prevent the need to
perform repeated system calls which have considerable overhead resulting from
the need to perform context switches. This increases the efficiency of data
retrieval when the file is small.</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.5in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.5in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>When a file is
large the fread and fwrite function, buffered read and write functions tend to
perform less efficiently because of the need to empty and refile the buffer
repeatedly (re-buffering). Re-buffering is </span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.5in;margin-bottom:.0001pt;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>Since Othello.txt
and hamlet.txt are both fairly small files, it makes sense that the buffered
output would be more efficient than the Unix system calls but when working with
larger files I would use the Unix calls to avoid the inefficiencies resulting
from the need to re-buffer. </span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-top:0in;margin-right:0in;margin-bottom:0in;
margin-left:1.5in;margin-bottom:.0001pt;text-indent:-1.5in;line-height:normal'><span
style='font-size:12.0pt;font-family:"Times New Roman",serif'>IMPROVEMENTS:   Personally,
the primary improvement I would need is to get the remaining functions to work
correctly. Also, adding some function that would detect file size and choose
between using Unix system call or </span><span style='font-family:"Cambria",serif;
color:black'>stdio.h functions would result in an increase in efficiency</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

<p class=MsoNormal style='margin-bottom:0in;margin-bottom:.0001pt;line-height:
normal'><span style='font-size:12.0pt;font-family:"Times New Roman",serif'>&nbsp;</span></p>

</div>

</body>

</html>

