vim.g.mapleader = " "
vim.keymap.set("n", "<leader>pv", vim.cmd.Ex)
vim.cmd('set autoindent')
vim.cmd('set tabstop=2')
vim.cmd('set shiftwidth=2')
vim.cmd('set expandtab')
vim.cmd('set relativenumber')
vim.cmd('syntax on')
vim.cmd('map<C-c> :!clang++ -DDEBUG -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -O2 -fsanitize=address,undefined -g -o %:r -std=c++20 -I./template/default -include ./template/default/bits/stdc++.h %<CR>')
vim.cmd('map<C-v> :!g++-15 -O2 -o %:r -std=c++20 %<CR>')

vim.cmd([[
function SetDefaultContext()
  :r ~/Documents/CP/template/default/tt.cpp
  :1,1d
  :call cursor(737, 2)
  :normal zz
endfunction]])
vim.cmd('autocmd BufNewFile *.cpp :call SetDefaultContext()')

vim.cmd('set termguicolors')
vim.cmd('colorscheme nightfox')
require('lualine').setup {
  options = {
    icons_enabled = true,
    theme = 'nightfly',
    component_separators = { left = '', right = ''},
    section_separators = { left = '', right = ''},
    disabled_filetypes = {
      statusline = {},
      winbar = {},
    },
    ignore_focus = {},
    always_divide_middle = true,
    globalstatus = false,
    refresh = {
      statusline = 1000,
      tabline = 1000,
      winbar = 1000,
    }
  },
  sections = {
    lualine_a = {},
    lualine_b = {},
    lualine_c = {'filename'},
    lualine_x = {'encoding', 'filetype'},
    lualine_y = {'location'},
    lualine_z = {}
  },
  inactive_sections = {
    lualine_a = {},
    lualine_b = {},
    lualine_c = {'filename'},
    lualine_x = {'location'},
    lualine_y = {},
    lualine_z = {}
  },
  tabline = {},
  winbar = {},
  inactive_winbar = {},
  extensions = {}
}
local palette = require('nightfox.palette').load('nightfox')
local Color = require("nightfox.lib.color")

local bg = Color.from_hex(palette.bg1)
print(bg:to_css())
