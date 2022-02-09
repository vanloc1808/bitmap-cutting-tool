# Bitmap-Cutting-Tool
This is a small tool for cutting a bitmap pictures into h * w parts, h parts by height and w parts by width.  

Usage:
```bash
    make
    cutt <file_name> -h <number of parts by height> -w <number of parts by width>
    # The arguments -w can stand before -h.
    # It is okay if we don't have 1 in 2 arguments, but not all.
    # To clean after use, type:
    make clean
```

Credit: Special thank to [Nghia Vo](https://github.com/mekanican)
