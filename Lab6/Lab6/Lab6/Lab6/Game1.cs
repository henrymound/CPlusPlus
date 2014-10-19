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

namespace Lab6
{
    /// <summary>
    /// This is the main type for your game
    /// </summary>
    public class Game1 : Microsoft.Xna.Framework.Game
    {
        const int WINDOW_WIDTH = 800;
        const int WINDOW_HEIGHT = 600;
        GraphicsDeviceManager graphics;
        SpriteBatch spriteBatch;
        TeddyBear bear1;
        TeddyBear bear2;

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
            /*creates two bear objects from the previously defined bear instnace variables.
            the constructor I used declares the bears with a random velocity
             1st bear is declared at coordinates (300, 200)
             2nd bear is declared at coordinates (200, 200)*/
            bear1 = new TeddyBear(Content, "teddybear0", 300, 200, WINDOW_WIDTH, WINDOW_HEIGHT);
            bear2 = new TeddyBear(Content, "teddybear1", 200, 200, WINDOW_WIDTH, WINDOW_HEIGHT);
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

            //every time the compiler calls the Update() method, the bears update themselves - creates movement
            bear1.Update();
            bear2.Update();

            base.Update(gameTime);
        }

        /// <summary>
        /// This is called when the game should draw itself.
        /// </summary>
        /// <param name="gameTime">Provides a snapshot of timing values.</param>
        protected override void Draw(GameTime gameTime)
        {
            GraphicsDevice.Clear(Color.Wheat);

            //the bears draw themselves with spriteBatch. spriteBatch then terminates itself after the bears are drawn
            spriteBatch.Begin(); 
            bear1.Draw(spriteBatch); 
            bear2.Draw(spriteBatch); 
            spriteBatch.End();

            base.Draw(gameTime);
        }
    }
}
