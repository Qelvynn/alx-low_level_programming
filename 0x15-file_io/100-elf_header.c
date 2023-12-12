#include <stdio.h>
#include <stdlib.h>
#include <elf.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define ELF_MAGIC "\x7F" "ELF"
#define READ_SIZE sizeof(Elf64_Ehdr)

/**
 * main - reads and prints the header of an ELF file
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
  struct stat statbuf;
  Elf64_Ehdr header;
  char buf[READ_SIZE];
  int fd;

  /* check if the number of arguments is correct */
  if (argc != 2)
    {
      fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
      return (1);
    }

  /* check if the file exists and is a regular file */
  if (stat(argv[1], &statbuf) == -1)
    {
      perror("stat");
      return (1);
    }
  if (!S_ISREG(statbuf.st_mode))
    {
      fprintf(stderr, "%s is not a regular file\n", argv[1]);
      return (1);
    }

  /* open the file and read the header */
  fd = open(argv[1], O_RDONLY);
  if (fd == -1)
    {
      perror("open");
      return (1);
    }
  if (read(fd, buf, READ_SIZE) != READ_SIZE)
    {
      perror("read");
      close(fd);
      return (1);
    }
  close(fd);

  /* copy the header to a struct and check if it is an ELF file */
  memcpy(&header, buf, READ_SIZE);
  if (strncmp(header.e_ident, ELF_MAGIC, 4) != 0)
    {
      fprintf(stderr, "%s is not an ELF file\n", argv[1]);
      return (98);
    }

  /* print the header information */
  printf("Magic:\t\t0x%02x %02x %02x %02x\n",
         header.e_ident[0], header.e_ident[1], header.e_ident[2], header.e_ident[3]);
  printf("Class:\t\t%s\n", header.e_ident[4] == ELFCLASS32 ? "ELF32" : "ELF64");
  printf("Data:\t\t%s\n", header.e_ident[5] == ELFDATANONE ? "2's complement, little endian" : "2's complement, big endian");
  printf("Version:\t\t0x%02x\n", header.e_ident[6]);
  printf("OS/ABI:\t\t%s\n", elf_osabi_stringtab_entry(header.e_ident[7]));
  printf("ABI Version:\t\t0x%02x\n", header.e_ident[8]);
  printf("Type:\t\t%s\n", elf_type_stringtab_entry(header.e_type));
  printf("Entry point address:\t0x%lx\n", header.e_entry);

  return (0);
}
