if [ "$1" = "clean" ]
then
   rm -rf classes precious_classes enc_precious_classes agent_bin agent_src/net_malhar*.header tools/.mypy*
else
    # Compile main sources. Use -h to generate header file
    javac -h ./agent_src -d classes src/net/malhar/*.java
    javac -d precious_classes precious_src/net/malhar/*.java
    mkdir -p enc_precious_classes/net/malhar

    find precious_classes -name "*.class" -exec python3 tools/base64_enc.py {} \;

    mkdir -p agent_bin
    cd agent_bin
    cmake ../agent_src
    cd ../agent_bin
    make
fi
