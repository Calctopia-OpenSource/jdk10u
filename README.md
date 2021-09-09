Welcome to Obliv-Java!
======================

![Crypto-Duke](crypto-duke.gif "Crypto-Duke ready to battle the Adversary!")

1. Installation of dependencies.

    For Ubuntu: sudo apt-get install ocaml libgcrypt20-dev ocaml-findlib opam m4
    For Fedora 27: sudo dnf install glibc-devel.i686 ocaml ocaml-ocamldoc ocaml-findlib ocaml-findlib-devel ocaml-ocamlbuild libgcrypt libgcrypt-devel perl-ExtUtils-MakeMaker perl-Data-Dumper
    For Mac OS (with Macports): sudo port install gcc5 ocaml ocaml-findlib opam libgcrypt +devel
    For Mac OS 10.15/11 (with homebrew): brew install gcc5 ocaml ocaml-findlib opam libgcrypt +devel. (+devel does not seem to be required on Mac OS 10.15)

2. If you are using OPAM as our package manager, and this is the first time you are using it, set it up:

   opam init
   opam switch 4.06.0
   eval `opam config env`
   opam install camlp4 ocamlfind ocamlbuild batteries

3. Configure OpenJDK (note: Zero virtual machine) and Obliv-C:

    ./configure --with-target-bits=64 --with-jvm-variants=zero --disable-warnings-as-errors
    [only for DEBUG compilation]
        ./configure --with-debug-level=slowdebug --with-target-bits=64 --with-native-debug-symbols=internal --with-jvm-variants=zero --disable-warnings-as-errors
    cd obliv-c && ./configure & cd ..

    If Java's `configure` fails due to missing dependencies (to either the
    [toolchain](#native-compiler-toolchain-requirements), [external libraries](
    #external-library-requirements) or the [boot JDK](#boot-jdk-requirements)),
    most of the time it prints a suggestion on how to resolve the situation on
    your platform. Follow the instructions, and try running `bash configure`
    again.

4. First make Obliv-C and then Obliv-Java's Open-JDK version:

    cd obliv-c && make && cd ..
    make

5. Verify your newly built JDK with secure computation: \

    `./build/*/jdk/bin/java -version`


Check the sub-directory "obliv-java" for the Obliv-Java source-to-source compiler.


For information about building OpenJDK from its official documentation,
please see either of these:

  * common/doc/building.html   (html version)
  * common/doc/building.md     (markdown version)

See http://openjdk.java.net/ for more information about OpenJDK.
