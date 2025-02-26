return {
	"nvim-lualine/lualine.nvim",
	config = function()
		require('lualine').setup({
			options = {
				theme = 'gruvbox',
				icons_enabled = false,
				section_separators = '',
				component_separators = ''
			},
			sections = {
				lualine_a = { 'mode' },
				lualine_b = { 'branch' },
				lualine_c = {
					{
						'filename',
						path = 3,
						shorting_target = 40,
					}
				},
				lualine_x = { 'encoding', 'fileformat', 'filetype' },
				lualine_y = { 'progress' },
				lualine_z = { 'location' },
			},
			inactive_sections = {
				lualine_a = {},
				lualine_b = {},
				lualine_c = { 'filename' },
				lualine_x = {},
				lualine_y = {},
				lualine_z = {},
			},
		})
	end
}
