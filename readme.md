Safe - Secure File Manager
==========================

Safe is a command-line tool written in C for securely managing encrypted files.
It allows users to add, view, update, and list encrypted files stored in a dedicated hidden directory.

Installation
------------

To install Safe, follow these steps:

1. **Clone the Repository** (Assuming you have the project in a Git repository. If not, just download or copy the project files to a local directory):

.. code-block:: bash

    git clone https://github.com/1darshanpatil/locker
    cd locker

2. **Compile the Program**:
   Use the provided Makefile to compile the program:

.. code-block:: bash

    make

3. **Install the Program**:
   Install the program to make it accessible system-wide:

.. code-block:: bash

    sudo make install

Usage
-----

After installation, you can use the `safe` command with the following options:

- **Add a New Encrypted File**:

.. code-block:: bash

    safe adduser

  Follow the prompts to enter the filename and encryption password.

- **View an Encrypted File**:

.. code-block:: bash

    safe viewfile

  Enter the name of the file you want to view (without the `.enc` extension) and its decryption password.

- **Update an Encrypted File**:

.. code-block:: bash

    safe updatefile

  Provide the filename (without `.enc`) and password to decrypt, edit, and re-encrypt the file.

- **List Encrypted Files**:

.. code-block:: bash

    safe showfiles

  Lists all encrypted files stored in `~/.safe`.

Uninstallation
--------------

To uninstall the program:

1. Remove the executable from `/usr/local/bin`:

.. code-block:: bash

    sudo rm /usr/local/bin/safe

2. Optionally, clean up the build files in your project directory:

.. code-block:: bash

    make clean

