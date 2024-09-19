# Simple Password Manager

This **Simple Password Manager** is a lightweight and straightforward C program that allows users to securely manage their credentials. It uses simple XOR encryption to protect passwords and stores the data in a text file. This is a beginner-friendly project for anyone looking to understand how to handle file operations and implement basic encryption techniques in C.

## Features

1. **Add New Credential**:
   - Save website, username, and password.
   - Passwords are stored with basic XOR encryption for security.
   
2. **View Credentials**:
   - View all saved credentials with decrypted passwords.
   
3. **Delete Credentials**:
   - Delete all stored credentials by removing the file containing them.

4. **Basic Encryption**:
   - Uses XOR encryption to protect passwords from being stored in plain text.

## How It Works

The application stores credentials (website, username, password) in a file (`credentials.txt`). Passwords are encrypted before being saved using a simple XOR encryption algorithm, and are decrypted when viewed.

## Usage

### Menu Options:
- **1. Add New Credential**: Allows you to input a website, username, and password, then saves them to the file after encrypting the password.
- **2. View Credentials**: Displays the saved website, username, and the decrypted password.
- **3. Delete Credentials**: Deletes all stored credentials by removing the file `credentials.txt`.
- **4. Exit**: Closes the program.

### Running the Program

1. Clone the repository:

    ```bash
    git clone https://github.com/yourusername/SimplePasswordManager.git
    cd SimplePasswordManager
    ```

2. Compile the program:

    ```bash
    gcc password_manager.c -o password_manager
    ```

3. Run the program:

    ```bash
    ./password_manager
    ```

### Example

```text
Password Manager Menu:
1. Add New Credential
2. View Credentials
3. Delete Credentials
4. Exit
Enter your choice: 1
Enter Website: github.com
Enter Username: user123
Enter Password: pass456
Credential added successfully!

Password Manager Menu:
1. Add New Credential
2. View Credentials
3. Delete Credentials
4. Exit
Enter your choice: 2

Stored Credentials:
Website: github.com, Username: user123, Password: pass456
```

## File Structure

- **password_manager.c**: Main source file containing the password manager program.
- **credentials.txt**: File where credentials (website, username, and encrypted password) are stored.

## Simple XOR Encryption

This password manager uses a simple XOR encryption technique to secure passwords. A single-character key (`'K'`) is used to encrypt and decrypt the passwords.

### Encryption/Decryption Function:

```c
void encryptDecrypt(char *data) {
    char key = 'K'; // Simple XOR key
    for (int i = 0; i < strlen(data); i++) {
        data[i] ^= key;
    }
}
```

### Important Note:
This encryption method is **not secure** for real-world applications but is implemented here for learning purposes. For serious password management, more robust encryption techniques such as AES should be used.

## Future Improvements

- Use a stronger encryption algorithm for better security.
- Implement user authentication (e.g., master password) to protect access to credentials.
- Add functionality to update or delete individual credentials.
- Store credentials in a more secure format (e.g., using databases or more secure file handling).

## Contributing

Contributions are welcome! If you have any ideas for improvements or find any issues, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

