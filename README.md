# Fil de Fer (FDF)

**An Ecole 42 project**

## File Structure

```bash
src
├── core
│   ├── color
│   │   ├── color.c
│   │   └── color.h
│   ├── core.c
│   ├── core.h
│   ├── event_callbacks
│   │   ├── event_callbacks.h
│   │   ├── keyboard_callbacks
│   │   │   ├── key_press.c
│   │   │   ├── key_release.c
│   │   │   ├── keyboard_callbacks.h
│   │   │   └── keyboard_sessions
│   │   │       ├── alpanum_key_press.c
│   │   │       ├── alpanum_key_release.c
│   │   │       ├── special_key_press.c
│   │   │       └── special_key_release.c
│   │   └── mouse_callbacks
│   │       ├── mouse_buttons.c
│   │       ├── mouse_callbacks.h
│   │       └── mouse_move.c
│   ├── event_hooks
│   │   ├── event_hooks.h
│   │   ├── keyboard_hooks.c
│   │   └── mouse_hooks.c
│   ├── frame
│   │   ├── render_background.c
│   │   ├── render_background.h
│   │   ├── render_frame.c
│   │   ├── render_frame.h
│   │   └── render_lines
│   │       ├── build_lines.c
│   │       ├── build_lines.h
│   │       ├── build_lines_utils.c
│   │       ├── build_lines_utils.h
│   │       ├── lines.h
│   │       ├── update_line.c
│   │       ├── update_line.h
│   │       └── update_rotation.c
│   └── state
│       ├── camera.c
│       ├── camera.h
│       ├── state.c
│       └── state.h
├── parser
│   ├── parse_file.c
│   ├── parse_file.h
│   ├── parse_matrix.c
│   ├── parse_point.c
│   ├── parser_matrix.c
│   ├── reader.c
│   ├── reader.h
│   ├── reader_list.c
│   ├── reader_matrix.c
│   ├── reader_nodes.c
│   └── reader_print.c
├── utils
│   ├── coordinates.c
│   ├── coordinates.h
│   ├── line.c
│   ├── line.h
│   ├── point.c
│   └── point.h
└── viewer
    ├── line
    │   ├── line_algorithms
    │   │   └── bresenham
    │   │       ├── bresenham.c
    │   │       ├── bresenham.h
    │   │       ├── bresenham_color.c
    │   │       ├── bresenham_utils.c
    │   │       └── bresenham_utils.h
    │   ├── viewer_line.c
    │   └── viewer_line.h
    ├── minilibx
    │   ├── devices_events
    │   │   ├── device_keys.h
    │   │   ├── devices_events.h
    │   │   ├── keyboard_events.c
    │   │   ├── mouse_events.c
    │   │   └── x11_events.h
    │   ├── minilibx.c
    │   ├── minilibx.h
    │   ├── minilibx_layer.c
    │   └── minilibx_structs.h
    ├── viewer.h
    ├── viewer_context.c
    └── viewer_context.h
```
