# libini

Very simple INI parser

## Usage

Your .ini file:

    [Category]
    Key=Value

Your .cpp file:

    auto ini = libini::parse(content_as_str);

    auto val = ini.get("Category", "Key");

## License

MIT
