#!/usr/bin/env python3

# Note: python should be installed on your Windows machine if you would like to use sysre in the command prompt
# systeminfo |find "Memory"
try:
  import os
  import sys
  import subprocess
  from colored import fg, bg, attr
except ImportError as err:
  print(f'Import Error: {}')
  
def main():
  pass
  
if __name__ == '__main__':
  try:
    main()
  except KeyboardInterrupt:
    try:
      print('Quiting program...')
      sys.exit(1)
    except SystemExit:
      os._exit(1)
