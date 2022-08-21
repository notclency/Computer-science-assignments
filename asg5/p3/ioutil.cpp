/* ioutil.cpp

  Modification History:
  2021 Jan ??   in the new version of Linux how EOF is handled changed.
                Upon detection it remains in the buffer, which results in
                it being infinitely read. The solution used to overcome
                this is to clear the stream and then stuff a space into
                the stream. Since a space is whitespace it is ignored in all cases.

  2021 June 10  readString would result in an infinite loop is maxlen < minlen.
                This only happens if you can't read the specs correctly. An extra
                case has been added to inform the user of this event and no read 
                is done.
                An infinite loop could be added here to force the user to CTRL-c
                to terminate the program, but this is NOT done in the event that 
                the useris entering these values and can correct the problem.
*/

#include "ioutil.h"
#include <iostream>
#include <cstring>
using namespace std;

void flush ();

int readInt(const char prompt[], bool& eof)
{
  int i;
  bool success = false;
  char ch, ch1;
  bool OK, negative = false;

  eof = false;

  do
  {
    cout << prompt;
    cin.get(ch);

    if (cin.eof())
    {
      cin.clear();
      cin.putback (' ');
      cin.get(ch);
      eof = true;
      success = true;
    }
    else if (ch == '\n')
    {
      cout << "INVALID INPUT - blank line entered -- please try again" << endl;
    }
    else if (ch != '-' && (ch < '0' || ch > '9'))
    {
      cout << "INVALID INPUT - input starts with non-numeric value -- please try again" 
           << endl;
      flush();
    }
    else
    {
      OK = true;
      if (ch == '-')
      {
        OK = false;
        cin.get(ch1);
        if (ch1 < '0' || ch1 > '9')
        {
          cout << "INVALID INPUT - input starts with non-numeric value -- please try again" 
               << endl;
          flush();
        }
        else
        {
          OK = true;
          negative = true;
          cin.putback(ch1);
        }
      }
      else
        cin.putback(ch);


      if (OK)
      {
        cin >> i;
        
        if (cin.fail())
        {
          cout << "INVALID INPUT - input value is ";
          if (negative)
          {
            cout << "less than minimum";
            negative = false;
          }
          else
          {
            cout << "greater than maximum";
          }
          cout << " allowed integer -- please try again" << endl;
          cin.clear();
          flush();
        }
        else
        {
          cin.get(ch);
          
          if (ch == '\n')
          {
            success = true;
            if (negative)
              i = -1*i;
          }
          else
          {
            cout << "INVALID INPUT - extra input after integer -- please try again" 
                 << endl;
            flush();
          }
        }
      }
    }
  } while (!success);
    
  return i;
}

bool readBool(const char prompt[], bool& eof)
{
  char  ch;
  bool  success = false,
        result = false;

  eof = false;

  do
  {
    cout << prompt;
    cin.get(ch);

    if (cin.eof())
    {
      cin.clear();
      cin.putback (' ');     /* needed to overwrite the EOF in the buffer */
      cin.get(ch);           /* needed to clear the buffer otherwise next */
                             /* attempted read will generate an error     */
      eof = true;
      success = true;
    }
    else
    {
      switch (ch)
      {
      case 'y':
      case 'Y':
        result = true;
        success = true;
        break;
      case 'n':
      case 'N':
        result = false;
        success = true;
        break;
      case '\n':
        cout << "INVALID - empty input  -- please try again" << endl;
        break;
      default:
        cout << "INVALID - (" << ch << ") is not y or n -- please try again" 
             << endl;
        flush();
        break;
      }
      if (success)
      {
        cin.get(ch);
        if (ch != '\n')
        {
          success = false;
          cout << "INVALID - characters following input are not allowed -- please try again"
               << endl;
          flush();
        }
      }
    }
  }
  while (!success);

  return result;
}


void readString(const char prompt[], char str[],
                int maxlen, int minlen, bool& eof)
{
  bool success = false;
  char ch;

  eof = false;
  if (maxlen < minlen)
  {
    cout << "ERROR - the input maximum length is smaller than the minimum"
         << " length." << endl
         << "No read is done - the returned string is garbage." << endl
         << "This issue needs to be fixed either in user input or the client program."
         << endl;
  }
  else
  {
    do
    {
      cout << prompt;
      cin.getline (str, maxlen+1, '\n');
      
      if (cin.eof())
      {
        cin.clear();
        cin.putback (' ');     /* needed to overwrite the EOF in the buffer */
        cin.get(ch);           /* needed to clear the buffer otherwise next */
                               /* attempted read will generate an error     */
        eof = true;
        success = true;
      }
      else if (static_cast <int> (strlen(str)) < minlen)
      {
        cout << "INVALID - input string is < minimum length (" 
             << minlen << ") -- please try again." << endl;
      }
      else if (cin.fail())
      {
        cout << "INVALID - input string longer than allowed -- please try again." 
             << endl;
        cin.clear();
        flush();
      }
      else
      {
        success = true;
      }
    }
    while (!success);
  }
  return;
}


void flush()
{
  char ch;

  do
  {
    cin.get(ch);
  } while (!cin.fail() && ch != '\n');

  return;
}
