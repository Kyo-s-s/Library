import os
import re

def remove_metadata(markdown_text):
    # メタ情報を示す正規表現パターン
    metadata_pattern = r'^---\s*([\s\S]*?)\s*---'

    # メタ情報を検索
    match = re.search(metadata_pattern, markdown_text)

    if match:
        # メタ情報が見つかった場合、それを削除
        metadata = match.group(0)
        markdown_text = markdown_text.replace(metadata, '')

    return markdown_text.strip()

script_directory = os.path.dirname(os.path.realpath(__file__))

folder_list = [folder for folder in os.listdir(script_directory) if os.path.isdir(os.path.join(script_directory, folder)) and not folder.startswith('.') and folder != "Test"]

content = ""

for folder_name in folder_list:
    content += f"# {folder_name}\n"
    folder_path = os.path.join(script_directory, folder_name)
    file_list_hpp = [file for file in os.listdir(folder_path) if file.endswith(".hpp")]
    for file_name_hpp in file_list_hpp:
        file_name_md = file_name_hpp.replace(".hpp", ".md")
        content += f"## {file_name_hpp}\n"
        try:
            with open(os.path.join(folder_path, file_name_md), "r") as file:
                content += remove_metadata(file.read()) + "\n"
        except:
            pass
        try:
            with open(os.path.join(folder_path, file_name_hpp), "r") as file:
                content += "```cpp\n" + file.read() + "\n```\n"
        except:
            pass


output_file_path = os.path.join(script_directory, "library.md")
with open(output_file_path, "w") as output_file:
    output_file.write(content)

