using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Audio;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.GamerServices;
using Microsoft.Xna.Framework.Graphics;
using Microsoft.Xna.Framework.Input;
using Microsoft.Xna.Framework.Media;

namespace Lab5
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;

        Texture2D photo1;
        Texture2D photo2;
        Texture2D photo3;

        Rectangle drawRectangle1;
        Rectangle drawRectangle2;
        Rectangle drawRectangle3;

        const int WINDOW_HEIGHT = 800;
        const int WINDOW_WIDTH = 600;

        public Game1()
        {
            graphics = new GraphicsDeviceManager(this);
            Content.RootDirectory = "Content";
            graphics.PreferredBackBufferWidth = WINDOW_WIDTH;
            graphics.PreferredBackBufferHeight = WINDOW_HEIGHT;
        }

        /// <summary>
        /// Allows the game to perform any initialization it needs to before starting to run.
        /// This is where it can query for any required services and load any non-graphic
        /// related content.  Calling base.Initialize will enumerate through any components
        /// and initialize them as well.
        /// </summary>
        protected override void Initialize()
        {
            // TODO: Add your initialization logic here

            base.Initialize();
        }

        /// <summary>
        /// LoadContent will be called once per game and is the place to load
        /// all of your content.
        /// </summary>
        protected override void LoadContent()
        {
            // Create a new SpriteBatch, which can be used to draw textures.
            spriteBatch = new SpriteBatch(GraphicsDevice);

            //load photo sprites
            photo1 = Content.Load<Texture2D>("1.jpg");
            photo2 = Content.Load<Texture2D>("2.jpg");
            photo3 = Content.Load<Texture2D>("3.jpg");

            //DRAW RECTANGLES WITH PHOTOS
            //rectangle 1 displays photo1 at full resolution at coordinates (300, 300)
            drawRectangle1 = new Rectangle(
                300,
                300,
                photo1.Width,
                photo1.Height);

            //rectangle 2 displays photo2 at full resolution at coordinates (400, 400)
            drawRectangle2 = new Rectangle(
                graphics.PreferredBackBufferWidth / 4,
                graphics.PreferredBackBufferHeight / 4,
                photo2.Width,
                photo2.Height);

            //rectangle 3 displays photo3 at full resolution at coordinates (200, 200)
            drawRectangle3 = new Rectangle(
                graphics.PreferredBackBufferWidth / 4,
                graphics.PreferredBackBufferHeight / 4,
                photo3.Width,
                photo3.Height);

        }

        /// <summary>
        /// UnloadContent will be called once per game and is the place to unload
        /// all content.
        /// </summary>
        protected override void UnloadContent()
        {
            // TODO: Unload any non ContentManager content here
        }

        /// <summary>
        /// Allows the game to run logic such as updating the world,
        /// checking for collisions, gathering input, and playing audio.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Update(GameTime gameTime)
        {
            // Allows the game to exit
            if (GamePad.GetState(PlayerIndex.One).Buttons.Back == ButtonState.Pressed)
                this.Exit();

            // TODO: Add your update logic here

            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.CornflowerBlue);

            // TODO: Add your drawing code here

            base.Draw(gameTime);
        }
    }
}
