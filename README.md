# Passhead

Copy first line of stdin to stdout, then execute a command. Useful to transform
table data with a tool that does not understand header line.

```console
$ cat data.tsv
index	value
1	1.23
2	4.56
3	7.89
4	0.12

$ passhead awk '{ sum += $2; print $1, sum }' < data.tsv
index	value
1	1.23
2	5.79
3	13.68
4	13.8
```


## Build

Clone the repository and build `passhead` with make:

```console
git clone https://github.com/snsinfu/passhead
cd passhead
make
```


## License

MIT License
