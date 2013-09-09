#!/bin/bash
#//////////////////////////////////////////////////////////////////////////////////////////
#//BOCA Online Contest Administrator. Copyright (c) 2003- Cassio Polpo de Campos.
#//It may be distributed under the terms of the Q Public License version 1.0. A copy of the
#//license can be found with this software or at http://www.opensource.org/licenses/qtpl.php
#//
#//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
#//INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
#//PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE COPYRIGHT HOLDER
#//OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT OR
#//CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
#//PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
#//OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
#///////////////////////////////////////////////////////////////////////////////////////////
#Last modified: 21/aug/2007 by cassio@ime.usp.br
#
# This script receives:
# $1 team_output
# $2 sol_output
# $3 languagename
# $4 problemname
# $5 problem_input
#
# BOCA reads the last line of the standard output
# and pass it to judges
#
# Next lines of this script just compares team_output and sol_output,
# although it is possible to change them to more complex evaluations.

if [ ! -r "$1" -o ! -r "$2" ]; then
  echo "Parameter problem"
  exit 43
fi
diff -q "$1" "$2" >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
  echo -e "diff \"$1\" \"$2\" # files match"
  echo "Files match exactly"
  exit 4
fi
diff -q -b "$1" "$2" >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
  echo -e "diff -c -b \"$1\" \"$2\" # files match"
  echo -e "diff -c \"$1\" \"$2\" # files dont match - see output"
  diff -c "$1" "$2"
  echo "Files match with differences in the amount of white spaces"
  exit 5
fi
diff -q -b -B "$1" "$2" >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
  echo -e "diff -c -b -B \"$1\" \"$2\" # files match"
  echo -e "diff -c -b \"$1\" \"$2\" # files dont match - see output"
  diff -c -b "$1" "$2"
  echo "Files match with differences in the amount of white spaces and blank lines"
  exit 5
fi
diff -q -i -b -B "$1" "$2" >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
  echo -e "diff -c -i -b -B \"$1\" \"$2\" # files match"
  echo -e "diff -c -b -B \"$1\" \"$2\" # files dont match - see output"
  diff -c -b -B "$1" "$2"
  echo "Files match if we ignore case and differences in the amount of white spaces and blank lines"
  exit 5
fi
diff -q -b -B -w "$1" "$2" >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
  echo -e "diff -c -b -B -w \"$1\" \"$2\" # files match"
  echo -e "diff -c -i -b -B \"$1\" \"$2\" # files dont match - see output"
  diff -c -i -b -B "$1" "$2"
  echo "Files match if we discard all white spaces"
  exit 5
fi
diff -q -i -b -B -w "$1" "$2" >/dev/null 2>/dev/null
if [ "$?" == "0" ]; then
  echo -e "diff -c -i -b -B -w \"$1\" \"$2\" # files match"
  echo -e "diff -c -b -B -w \"$1\" \"$2\" # files dont match - see output"
  diff -c -b -B -w "$1" "$2"
  echo "Files match if we ignore case and discard all white spaces"
  exit 5
fi
echo -e "diff -c -i -b -B -w \"$1\" \"$2\" # files dont match - see output"
diff -c -i -b -B -w "$1" "$2"
echo "Differences found"
exit 6
