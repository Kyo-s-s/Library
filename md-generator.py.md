---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\nimport re\n\ndef remove_metadata(markdown_text):\n    # \u30E1\
    \u30BF\u60C5\u5831\u3092\u793A\u3059\u6B63\u898F\u8868\u73FE\u30D1\u30BF\u30FC\
    \u30F3\n    metadata_pattern = r'^---\\s*([\\s\\S]*?)\\s*---'\n\n    # \u30E1\u30BF\
    \u60C5\u5831\u3092\u691C\u7D22\n    match = re.search(metadata_pattern, markdown_text)\n\
    \n    if match:\n        # \u30E1\u30BF\u60C5\u5831\u304C\u898B\u3064\u304B\u3063\
    \u305F\u5834\u5408\u3001\u305D\u308C\u3092\u524A\u9664\n        metadata = match.group(0)\n\
    \        markdown_text = markdown_text.replace(metadata, '')\n\n    return markdown_text.strip()\n\
    \nscript_directory = os.path.dirname(os.path.realpath(__file__))\n\nfolder_list\
    \ = [folder for folder in os.listdir(script_directory) if os.path.isdir(os.path.join(script_directory,\
    \ folder)) and not folder.startswith('.') and folder != \"Test\"]\n\ncontent =\
    \ \"\"\n\nfor folder_name in folder_list:\n    content += f\"# {folder_name}\\\
    n\"\n    folder_path = os.path.join(script_directory, folder_name)\n    file_list_hpp\
    \ = [file for file in os.listdir(folder_path) if file.endswith(\".hpp\")]\n  \
    \  for file_name_hpp in file_list_hpp:\n        file_name_md = file_name_hpp.replace(\"\
    .hpp\", \".md\")\n        content += f\"## {file_name_hpp}\\n\"\n        try:\n\
    \            with open(os.path.join(folder_path, file_name_md), \"r\") as file:\n\
    \                content += remove_metadata(file.read()) + \"\\n\"\n        except:\n\
    \            pass\n        try:\n            with open(os.path.join(folder_path,\
    \ file_name_hpp), \"r\") as file:\n                content += \"```cpp\\n\" +\
    \ file.read() + \"\\n```\\n\"\n        except:\n            pass\n\n\noutput_file_path\
    \ = os.path.join(script_directory, \"library.md\")\nwith open(output_file_path,\
    \ \"w\") as output_file:\n    output_file.write(content)\n\n"
  dependsOn: []
  isVerificationFile: false
  path: md-generator.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: md-generator.py
layout: document
redirect_from:
- /library/md-generator.py
- /library/md-generator.py.html
title: md-generator.py
---
