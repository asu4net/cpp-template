#pragma once

auto os_read_entire_file(std::string_view filename) -> std::string;
auto os_trim(std::string text) -> std::string;

// @Note: This is relative to the exe path. Ex: "\\..\\..\\assets" would set the wdir two folders up the exe, inside the assets dir.
auto os_set_working_dir(const std::string& path) -> void;
auto os_get_time() -> f64;