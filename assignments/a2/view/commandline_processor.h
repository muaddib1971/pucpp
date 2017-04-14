namespace view
{
    enum filetype
    {
        ASCII, BINARY
    };

    class commandline_processor
    {
        std::tuple<filetype, filetype> process_commands(
            stl_container<std::string>);
    };
}
