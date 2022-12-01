import base64
import sys

filename = sys.argv[1]
if (filename.startswith("precious_classes")):
    file = open(filename, "rb");
    file_content = file.read()
    file.close();

    enc_file_name = filename\
        .replace("precious_classes", "enc_precious_classes")\
        .replace(".class", ".eclass")
        
    enc_file = open(enc_file_name, "wb");
    enc_file.write(base64.b64encode(file_content));
    enc_file.close();
else:
    print("Expected file to be in precious_classes directory")
    sys.exit(1)


