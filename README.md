# C-program-to-encrypt-and-decrypt-the-string-using-Caesar-Cypher-Algorithm & C program to encrypt and decrypt the string using RSA algorithm.

#1st option
For encryption and decryption, we have used 3 as a key value.

While encrypting the given string, 'shift' value is added to the ASCII value of the characters. Similarly, for decrypting the string, 'shift' value is subtracted from the ASCII value of the characters to print an original string.


#2nd option
C program to encrypt and decrypt the string using RSA algorithm.
RSA is another method for encrypting and decrypting the message. It involves public key and private key, where the public key is known to all and is used to encrypt the message whereas private key is only used to decrypt the encrypted message.

   It has mainly 3 steps:

    1: Creating Keys

      Select two large prime numbers x and y
      Compute n = x * y
      where n is the modulus of private and the public key
      Calculate totient function, ø (n) = (x − 1)(y − 1)
      Choose an integer e such that e is coprime to ø(n) and 1 < e < ø(n).
      e is the public key exponent used for encryption
      Now choose  d, so that d · e mod ø (n) = 1, i.e., >code>d is the multiplicative inverse of e in mod ø (n)

    2: Encrypting Message

       Messages are encrypted using the Public key generated and is known to all.
       The public key is the function of both e and n i.e. {e,n}.
       If M is the message(plain text), then ciphertext

       C = M ^ n( mod n )

    3: Decrypting Message

       The private key is the function of both d and n i.e {d,n}.
       If C is the encrypted ciphertext, then the plain decrypted text M is

       M = C ^ d ( mod n )