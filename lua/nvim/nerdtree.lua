return {
  "preservim/nerdtree",
  config = function()
    vim.keymap.set("n", "<leader>n", ":NERDTreeToggle<CR>", { desc = "Toggle NerdTree"})
    vim.cmd('autocmd BufEnter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif')
  end
}
