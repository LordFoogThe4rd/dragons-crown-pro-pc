// The launcher's own "choose a file" window: a modal list of folders and .pkg files, or of folders only for an already
// extracted game, usable with the mouse, the keyboard and a controller. It stands in for the desktop's chooser where
// there is none.
#pragma once

#include <filesystem>
#include <optional>
#include <string>
#include <vector>

#include <imgui.h>

#include "file_browser.h"
#include "trg/launcher.h"

namespace dcp {

class PackageBrowser {
public:
    // Starts at the folder that holds a .pkg (the program's folder, Downloads, a drive...), else the program's folder.
    void Open(const std::filesystem::path& program_folder);
    // The same window for an already extracted game: only folders are listed, and the open folder itself can be chosen.
    void OpenForFolder(const std::filesystem::path& program_folder);
    bool active() const { return active_; }

    // Draws the window while it is open; returns the file or folder once the player chose one. `font` is nullptr for
    // the current font.
    std::optional<std::filesystem::path> Draw(ImFont* font, float font_size, const trg::Theme& theme);

private:
    void Show(const std::filesystem::path& program_folder, bool folder);
    void Go(const std::filesystem::path& folder);

    bool active_ = false;
    bool folders_only_ = false;
    bool popup_open_ = false;
    bool focus_list_ = false;
    bool show_all_ = false;
    std::filesystem::path folder_;
    std::vector<Place> places_;
    FolderListing listing_;
};

} // namespace dcp
